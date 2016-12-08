#include <stdio.h>
#define size 4

int top = -1;

void Print(int St[])
{
	int i;
	
	for (i = 0; i <= top; i++)
		printf("%d ", St[i]);
	
	printf("\n");
}

void Push(int St[])
{
	if (top == size - 1)
	{
		printf("Stack Overflow.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &St[++top]);
	
	Print(St);
}

void Pop(int St[])
{
	if (top == -1)
	{
		printf("Stack Underflow.\n");
		return;
	}
	
	top--;
	
	Print(St);
}

int main()
{
	int n;
	int St[size];
	
	do
	{
		printf("1. Print Stack\n");
		printf("2. Insert Element in Stack\n");
		printf("3. Delete Element in Stack\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(St); break;
			case 2: Push(St); break;
			case 3: Pop(St); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}