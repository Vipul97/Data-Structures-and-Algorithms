#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top = NULL;
struct node *curr = NULL;

void Print()
{
	curr = top;
	
	if (curr == NULL)
		printf("Stack is Empty.");
	
	else
		while (curr)
		{
			printf("%d ", curr->data);
			curr = curr->next;
		}
	
	printf("\n");
}

void Push()
{
	curr = (struct node*)malloc(sizeof(struct node));
	
	if (curr == NULL)
	{
		printf("Stack Overflow.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &curr->data);
	
	if (top == NULL)
	{
		top = curr;
		top->next = NULL;
	}
	
	else
	{
		curr->next = top;
		top = curr;
	}
	
	Print();
}

void Pop()
{
	struct node *temp = NULL;
	
	if (top == NULL)
	{
		printf("Stack Underflow.\n");
		return;
	}
	
	temp = top;
	top = top->next;
	temp->next = NULL;
	free(temp);
	
	Print();
}

int main()
{
	int n;
	
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
			case 1: Print(); break;
			case 2: Push(); break;
			case 3: Pop(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}