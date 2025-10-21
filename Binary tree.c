#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node*left;
	struct node*right;	
}*root = NULL;

struct node* create_node()
{
	int data1,op;
	printf("\nEnter option: ");
	scanf("%d", &op);
	struct node*newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(op == -1)
	{
		return NULL;
	}else {
		printf("\nEnter data: ");
		scanf("%d", &data1);
		newNode->data = data1;
		newNode->left = newNode->right = NULL;
		newNode->left = create_node();
		newNode->right = create_node();
	}
}
void pre_order(int *root)
{
	struct node*node;
	node = root;
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
int main() 
{
	int data1;
	struct node*node;
	printf("Enter the elements of the tree(-1 to terminate):\n");
	root = create_node();
	printf("\nTraversal in pre-order:\n");
	pre_order(root);
	return 0;
}
