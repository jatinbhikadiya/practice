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

int main(int argc, char * argv[]){
	struct Graph* G = createGraph(5,5);
	return 0;
}
