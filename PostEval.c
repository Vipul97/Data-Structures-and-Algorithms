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

void Push(int St[], int op)
{
	if (top == size - 1)
	{
		printf("Stack Overflow.\n");
		return;
	}

	St[++top] = op;
	
	Print(St);
}

int Pop(int St[])
{
	int op;
	
	if (top == -1)
	{
		printf("Stack Underflow.\n");
		return 0;
	}
	
	op = St[top];
	top--;
	
	return op;
}

void Eval(int St[])
{
	char s[100];
	int i = 0;
	int op1, op2;
	
	printf("Enter Expression: ");
	scanf("%s", s);

	while (s[i] != '\0')
	{
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || 
			s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
			Push(St, s[i] - '0');
		
		else
		{
			op1 = Pop(St);
			op2 = Pop(St);
			
			if (s[i] == '+')
				Push(St, op2 + op1);
			
			else if (s[i] == '-')
				Push(St, (op2 - op1));
			
			else if (s[i] == '*')
				Push(St, (op2 * op1));
			
			else
				Push(St, (op2 / op1));
		}
		
		i++;
	}
		
	printf("\n");
}


int main()
{
	int n;
	int St[size];
	
	do
	{
		printf("1. Print Stack\n");
		printf("2. Evaluate Postfix Expression of Stack\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(St); break;
			case 2: Eval(St); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}