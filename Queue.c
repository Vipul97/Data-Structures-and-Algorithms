#include <stdio.h>
#define size 4

int front = -1;
int rear = -1;

void Print(int Q[])
{
	int i;
	
	if (rear == -1)
	{
		printf("Queue is Empty.\n");
		return;
	}
	
	for (i = front; i <= rear; i++)
		printf("%d ", Q[i]);
	
	printf("\n");
}

void Enqueue(int Q[])
{
	if (rear == size - 1)
	{
		printf("Queue Overflow.\n");
		return;
	}

	else if (rear ==  -1)
		front = 0;

	printf("Enter Data: ");
	scanf("%d", &Q[++rear]);
	
	Print(Q);
}

void Dequeue(int Q[])
{
	if (rear == -1)
	{
		printf("Queue Underflow.\n");
		return;
	}
	
	printf("%d popped\n", Q[front]);
	
	if (front == rear)
		front = rear = -1;
	
	else
		front++;
	
	Print(Q);
}

int main()
{
	int n, Q[size];
	
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
			case 1: Print(Q); break;
			case 2: Enqueue(Q); break;
			case 3: Dequeue(Q); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}