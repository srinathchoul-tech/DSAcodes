#include<stdio.h>

struct  node 
{
	int data;
	struct node*back;
	struct node*next;
}*head = NULL;

int main()
{
	int data1;
	struct node*temp,*newNode,*end;
	printf("Enter the elements of Linked lists:\n");
	while(1)
	{
		scanf("%d", &data1);
		if(data1 == -1)
		{
			break;
		}
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->back = NULL;
		newNode->data = data1;
		newNode->next = NULL;
		if(head == NULL)
		{
			head = newNode;
			temp = head;
		} else {
			temp->next = newNode;
			newNode->back = temp;
			temp = newNode;
		}
	}
	if(temp != NULL)
	{
		temp->next = head;
		head->back = temp;
	}
	printf("\nPrinting the Double Circular LL:\n");
	if(head != NULL)
	{
		temp = head;
		while(1)
		{
			printf("%d -> ", temp->data);
			temp = temp->next;
			if(temp == head)
			{
				end = temp->back;
				break;
			}
		}
		printf("%d", temp->data);
	}
	printf("\nPrinting the Double LL in Reverse Order:\n");
	while(1)
	{
		printf("%d -> ", end->data);
		end = end->back;
		if(end == head->back)
		{
			printf("%d", end->data);
			break;
		}
	}
	return 0;
}
