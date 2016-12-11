#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
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
			printf("%d ", curr->key);
			curr = curr->next;
		}
	
	printf("\n");
}

int StackEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

void Push(struct node *x)
{
   	if (top == NULL)
	{
		top = x;
		top->next = NULL;
	}
	
	else
	{
		x->next = top;
		top = x;
	}
}

void Pop()
{
    struct node *temp = NULL;

    if (StackEmpty())
	{
		printf("Underflow.\n");
		return;
	}
	
	temp = top;
	top = top->next;
	temp->next = NULL;
	free(temp);
}

int main()
{
	int n, k;
	
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
            case 2: printf("Enter Key: ");
                    scanf("%d", &k);
                    curr = (struct node*)malloc(sizeof(struct node));
                    curr->key = k;
                    Push(curr);
                    Print();
                    break;
			case 3: Pop(); 
                    Print();
                    break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
