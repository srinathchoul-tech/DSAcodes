#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node*next;
	struct node*back;
}*head = NULL;

void insert_at_beg(int data1)
{
	struct node*newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data1;
	if(head == NULL)
	{
		head = newNode;
		newNode->back = NULL;
		newNode->next = NULL;
	} else {
		newNode->next = head;
		newNode->back = NULL;
		head->back = newNode;
		head = newNode;
	}
}
void insert_at_end(int data1)
{
	struct node*newNode,*temp = head;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data1;
	while(temp ->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->back = temp;
	newNode->next = NULL;
}
void insert_at_pos(int data1,int pos)
{
	int cnt = 0;
	struct node*newNode,*temp = head;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data1;
	while(temp->next != NULL)
	{
		cnt++;
		if(cnt == pos-1)
		{
			newNode->next = temp->next;
			temp->next->back = newNode;
			temp->next = newNode;
			newNode->back = temp;
			printf("\n%d inserted at %d position\n", data1,pos);
			break;
		} 
		temp = temp->next;
	}
}
void delete_at_beg()
{
	head = head->next;
	head->back = NULL;
	printf("\nElement deleted at beginning");
}
void delete_at_end()
{
	struct node*temp = head,*prev;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	prev = temp->back;
	temp->back = NULL;
	prev->next = NULL;
	printf("\nElement deleted at end");
}
void delete_at_pos(int pos)
{
	struct node*temp = head,*prev;
	int cnt = 0;
	while(temp->next != NULL)
	{
		cnt++;
		if(cnt == pos)
		{
			prev = temp->back;
			prev->next = prev->next->next;
			temp->next->back = prev;
			temp->back = NULL;
			temp->next = NULL;
			printf("\nElement deleted at %d position", pos);
			break;
		}
		temp = temp->next;
	}
}
void search(int key)
{
	struct node*temp = head;
	int cnt = 0,check = 0;
	while(temp != NULL)
	{
		cnt++;
		if(temp->data == key)
		{
			printf("\n%d found at %d position(index)", key,cnt);
			check = 1;
			break;
		} else {
			temp = temp->next;
		}
	}
	if(check == 0)
	{
		printf("\nElement not found");
	}
}
void display()
{
	struct node*temp = head;
	while(temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
int main() 
{
	int data1,op,pos,key;
	while(1)
	{
		printf("\nSelect:\n");
		printf("1: insert at beginning\n");
		printf("2: insert at end\n");
		printf("3: insert at position\n");
		printf("4: delete at beginning\n");
		printf("5: delete at end\n");
		printf("6: delete at position\n");
		printf("7: search\n");
		printf("8: display\n");
		printf("9: exit\n");
		printf("Enter option: ");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
				printf("\nEnter element to insert at beginning: ");
				scanf("%d", &data1);
				insert_at_beg(data1);
				break;
			case 2:
				printf("\nEnter element to insert at end: ");
				scanf("%d", &data1);
				insert_at_end(data1);
				break;
			case 3:
				printf("\nEnter element to insert along with it's position: ");
				scanf("%d%d", &data1,&pos);
				insert_at_pos(data1,pos);
				break;
			case 4:
				delete_at_beg();
				break;
			case 5:
				delete_at_end();
				break;
			case 6:
				printf("\nEnter position of the element to delete: ");
				scanf("%d", &pos);
				delete_at_pos(pos);
				break;
			case 7:
				printf("\nEnter element to search: ");
				scanf("%d", &key);
				search(key);
				break;
			case 8:
				printf("\nElements of the Linked list:\n");
				display();
				break;
			case 9:
				printf("\nExiting...");
				return 0;
			default:
				printf("\nWrong choice");
				break;
		}
	}
	return 0;
}
