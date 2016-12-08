#include <stdio.h>
#define size 4

int front = -1;
int rear = -1;

void Print(int Q[])
{
	int i, last;
	
	if (front == -1)
	{
		printf("Queue is Empty.\n");
		return;
	}
	
	if (front <= rear)
		last = rear;
	
	else
		last = rear + size;
	
	for (i = front; i <= last; i++)
		printf("%d ", Q[i % size]);
	
	printf("\n");
}

void Enqueue(int Q[])
{
	if ((rear+1) % size == front)
	{
		printf("Queue Overflow.\n");
		return;
	}
	
	else if (rear == -1)
		front++;
	
	rear = (rear+1) % size;
	
	printf("Enter Data: ");
	scanf("%d", &Q[rear]);
	
	Print(Q);
}

void Dequeue(int Q[])
{
	if (front == -1)
	{
		printf("Queue Underflow.\n");
		return;
	}
	
	else if (front == rear)
		front = rear = -1;
	
	else
		front = (front+1) % size;
	
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