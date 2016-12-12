#include <stdio.h>
#define length 100

int head = 0, tail = 0;

void Print(int Q[])
{
	int i;

	for (i = head; i != tail; i = (i + 1) % length)
		printf("%d ", Q[i]);

	printf("\n");
}

void Enqueue(int Q[], int x)
{
	if (head == (tail + 1) % length)
	{
		printf("Overflow.\n");
		return;
	}

	Q[tail] = x;

	if (tail == length - 1)
		tail = 0;
	else
		tail++;
}

int Dequeue(int Q[])
{
	if (head == tail)
	{
		printf("Underflow.\n");
		return;
	}

	int x = Q[head];

	if (head == length - 1)
		head = 0;
	else
		head++;

	return x;
}

int main()
{
	int n, x;
	int Q[length];

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
		case 2: printf("Enter Value: ");
			scanf("%d", &x);
			Enqueue(Q, x);
			Print(Q);
			break;
		case 3: Dequeue(Q);
			Print(Q);
			break;
		case 0: break;
		default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
