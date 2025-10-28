#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node*left;
	struct node*right;	
}*root = NULL;

struct node* insert(struct node*newNode, int ele)
{
	if(newNode == NULL)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = ele;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
	} else {
		if(ele < newNode->data)
		{
			newNode->left = insert(newNode->left,ele);
		} else {
			newNode->right = insert(newNode->right,ele);
		}
		return newNode;
	}
}

void pre_order(struct node *node)
{
	printf("%d ", node->data);
	if(node->left != NULL)
	{
		pre_order(node->left);
	} 
	if(node->right != NULL)
	{
		pre_order(node->right);
	}
}

void post_order(struct node*node)
{
	if(node->left != NULL)
	{
		post_order(node->left);
	} 
	if(node->right != NULL)
	{
		post_order(node->right);
	}
	printf("%d ", node->data);
}

int main() 
{
	int data1;
	printf("Enter the elements of the tree(-1 to terminate):\n");
	root = insert(root, 100);
	root = insert(root,50);
	root = insert(root,110);
	pre_order(root);
	return 0;
}
