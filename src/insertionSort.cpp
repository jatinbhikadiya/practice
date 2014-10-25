
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stack>
#include <queue>
/* Link list node */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int height(struct node* root){
	if(root==NULL)
	{
		return 0;
	}
	return std::max(height(root->left) ,height(root->right)) +1;
}

void printSpiral(struct node* root){
	if(root==NULL)
	{
		return;
	}
	std::stack<struct node*> s1;
	std::queue<struct node*> q;

	s1.push(root);
	while(!s1.empty() || !q.empty()){

		while(!s1.empty())
		{
			struct node *temp = s1.top();
			s1.pop();
			printf("%d ",temp->data);
			if(temp->left)
				q.push(temp->left);

			if(temp->right)
				q.push(temp->right);
		}
		while(!q.empty())
		{
			struct node *temp = q.front();
			q.pop();
			printf("%d ",temp->data);
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right);
		}
	}

}

/* Driver program to test above functions*/
int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printf("height of the treee is :%d\n",height(root));
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);

    return 0;
}
