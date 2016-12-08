#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	int priority;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
struct node *curr = NULL;

void Print()
{
	curr = front;
	
	if (curr == NULL)
		printf("Priority Queue is Empty.");
	
	else
		while (curr)
		{
			printf("(%d, %d) ", curr->data, curr->priority);
			curr = curr->next;
		}

	printf("\n");
}

void Enqueue()
{
	curr = (struct node*)malloc(sizeof(struct node));
	struct node *temp1 = NULL;
	struct node *temp2 = NULL;
	
	if (curr == NULL)
	{
		printf("Queue Overflow.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &curr->data);
	printf("Enter Priority: ");
	scanf("%d", &curr->priority);
	
	if (rear == NULL)
	{
		front = curr;
		rear = curr;
		rear->next = NULL;
	}
	
	else if (curr->priority < front->priority)
	{
		curr->next = front;
		front = curr;
	}
	
	else if (curr->priority > rear->priority)
	{
		rear->next = curr;
		rear = curr;
	}
	
	else
	{
		temp1 = front;

		while (curr->priority > temp1->priority && temp1->next != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
		}
		
		temp2->next = curr;
		curr->next = temp1;
	}

	Print();
}

void Dequeue()
{
	struct node *temp = NULL;
	
	if (front == NULL)
	{
		printf("Queue Underflow.\n");
		return;
	}
	
	temp = front;
	
	if (front == rear)
		front = rear = NULL;
	else
		front = front->next;
	
	temp->next = NULL;
	free(temp);
	
	Print();
}

int main()
{
	int n;
	
	do
	{
		printf("1. Print Queue\n");
		printf("2. Enqueue\n");
		printf("3. Dequeue\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(); break;
			case 2: Enqueue(); break;
			case 3: Dequeue(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}