#include <stdio.h>
#define size 100

int top = -1;

void Print(int St[])
{
	int i;

	for (i = 0; i <= top; i++)
		printf("%d ", St[i]);

	printf("\n");
}

int StackEmpty(int S[])
{
	if (top == -1)
		return 1;
	return 0;
}

void Push(int S[], int x)
{
	S[++top] = x;
}

int Pop(int S[])
{
	if (StackEmpty(S))
	{
		printf("Underflow.\n");
		return;
	}

	top--;
	return S[top + 1];
}

int main()
{
	int n, x;
	int S[size];

	do
	{
		printf("1. Print Stack\n");
		printf("2. Push Stack\n");
		printf("3. Pop Stack\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Print(S);
			break;
		case 2:
			printf("Enter Key: ");
			scanf("%d", &x);
			Push(S, x);
			Print(S);
			break;
		case 3:
			Pop(S);
			Print(S);
			break;
		case 0:
			break;
		default:
			printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
