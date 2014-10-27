// Kruskal's algortihm to find Minimum Spanning Tree of a given connected,
// undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iostream>
// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{	struct Graph* graph;
	//graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph =new Graph();
	graph->V = V;
	graph->E = E;
	graph->edge =new Edge[graph->E];
	//graph->edge = (struct Edge*) malloc(sizeof(struct Edge)*graph->E);
	//std::cout<<sizeof(graph->edge)<<std::endl;
	return graph;
}
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
//Union find algorithm function - Union, find anf struct subset
// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(struct Graph* graph){
	int V = graph->V;
	struct Edge result[V];
	//use qsort to sort the graph according to weight of edges in
	//increasing order. It takes four arguments:
	//base pointer, size of array, size of each element, comparator function
	qsort(graph->edge,graph->E, sizeof(graph->edge[0]),myComp);

	// Allocate memory for creating V ssubsets
	struct subset *subsets =
			(struct subset*) malloc( V * sizeof(struct subset) );

	// Create V subsets with single elements
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	int i=0,e=0;
	while (e < V - 1)
	    {
	        // Step 2: Pick the smallest edge. And increment the index
	        // for next iteration
	        struct Edge next_edge = graph->edge[i++];

	        int x = find(subsets, next_edge.src);
	        int y = find(subsets, next_edge.dest);

	        // If including this edge does't cause cycle, include it
	        // in result and increment the index of result for next edge
	        if (x != y)
	        {
	            result[e++] = next_edge;
	            Union(subsets, x, y);
	        }
	        // Else discard the next_edge
	    }

	    // print the contents of result[] to display the built MST
	    printf("Following are the edges in the constructed MST\n");
	    for (i = 0; i < e; ++i)
	        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
	                                                   result[i].weight);
	    return;
}

int main(int argc, char * argv[]){
	/* create following weighted graph
	             10
	        0--------1
	        |  \     |
	       6|   5\   |15
	        |      \ |
	        2--------3
	            4       */
	    int V = 4;  // Number of vertices in graph
	    int E = 5;  // Number of edges in graph
	    struct Graph* graph = createGraph(V, E);
	    graph->edge[0].src=0;
	    graph->edge[0].dest=1;
	    graph->edge[0].weight=10;

	    // add edge 0-2
	    graph->edge[1].src = 0;
	    graph->edge[1].dest = 2;
	    graph->edge[1].weight = 6;

	    // add edge 0-3
	    graph->edge[2].src = 0;
	    graph->edge[2].dest = 3;
	    graph->edge[2].weight = 5;

	    // add edge 1-3
	    graph->edge[3].src = 1;
	    graph->edge[3].dest = 3;
	    graph->edge[3].weight = 15;

	    // add edge 2-3
	    graph->edge[4].src = 2;
	    graph->edge[4].dest = 3;
	    graph->edge[4].weight = 4;

	    KruskalMST(graph);
	    return 0;
}
