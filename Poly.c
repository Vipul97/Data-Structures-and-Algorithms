#include <stdio.h>
#include <stdlib.h>

struct node
{
	int coeff;
	int expo;
	struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *head3 = NULL;
struct node *curr1 = NULL;
struct node *curr2 = NULL;
struct node *curr3 = NULL;

void Print(struct node *head, struct node *curr)
{
	curr = head;
	
	if (curr == NULL)
		printf("The Polynomial is Empty.");
	
	else
	{
		printf("The Equation of Polynomial is:\n");
		
		while (curr)
		{
			if (curr->next != NULL)
				printf("%d^x%d + ", curr->coeff, curr->expo);
			
			else
				printf("%d^x%d\n", curr->coeff, curr->expo);
			
			curr = curr->next;
		}
	}
	
	printf("\n");
}

void AddTerm(struct node **head, struct node **curr)
{
	struct node *temp = *head;
	*curr = (struct node*)malloc(sizeof(struct node));
	
	if (*curr == NULL)
	{
		printf("Error.\n");
		return;
	}
	
	printf("Enter Coefficient: ");
	scanf("%d", &(*curr)->coeff);
	printf("Enter Power: ");
	scanf("%d", &(*curr)->expo);
	
	if (*head == NULL)
		*head = *curr;
	
	else
	{
		while ((*curr)->expo != temp->expo && temp->next != NULL)
			temp = temp->next;
		
		if ((*curr)->expo == temp->expo)
			temp->coeff += (*curr)->coeff;
		
		else
			temp->next = *curr;
	}
	
	(*curr)->next = NULL;
	
	Print(*head, *curr);
}

void AddPoly()
{
	curr1 = head1;
	curr2 = head2;
	curr3 = head3;
	
	while (curr1 && curr2)
	{
		if (head3 == NULL)
		{
			curr3 = (struct node*)malloc(sizeof(struct node));
			head3 = curr3;
		}
		
		else
		{
			curr3->next = (struct node*)malloc(sizeof(struct node));
			curr3 = curr3->next;
		}
        
		if (curr1->expo > curr2->expo) 
		{
			curr3->expo = curr1->expo;
			curr3->coeff = curr1->coeff;
			curr1 = curr1->next;
        }
        
		else if (curr1->expo < curr2->expo) 
		{
			curr3->expo = curr2->expo;
			curr3->coeff = curr2->coeff;
			curr2 = curr2->next;
		}
		
		else 
		{
			curr3->expo = curr1->expo;
			curr3->coeff = curr1->coeff + curr2->coeff;
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
	}
 
    while (curr1)
    {
		if (head3 == NULL)
		{
			curr3 = (struct node*)malloc(sizeof(struct node));
			head3 = curr3;
		}
		
		else
		{
			curr3->next = (struct node*)malloc(sizeof(struct node));
			curr3 = curr3->next;
		}
		
        curr3->expo = curr1->expo;
        curr3->coeff = curr1->coeff;
        curr1 = curr1->next;
    }
        
    while (curr2)
    {
		if (head3 == NULL)
		{
			curr3 = (struct node*)malloc(sizeof(struct node));
			head3 = curr3;
		}
		
		else
		{
			curr3->next = (struct node*)malloc(sizeof(struct node));
			curr3 = curr3->next;
		}
		
    	curr3->expo = curr2->expo;
        curr3->coeff = curr2->coeff;
        curr2 = curr2->next;
    }

    if (curr3 != NULL)
	{
		curr3->next = NULL;
    
		Print(head3, curr3);
	}
	
	else
		printf("The Added Polynomial is Empty.\n");
}

int main()
{
	int n;
	
	do
	{
		printf("1. Print First Polynomial\n");
		printf("2. Print Second Polynomial\n");	
		printf("3. Add Term to First Polynomial\n");
		printf("4. Add Term to Second Polynomial\n");
		printf("5. Add 2 Polynomials\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(head1, curr1); break;
			case 2: Print(head2, curr2); break;
			case 3: AddTerm(&head1, &curr1); break;
			case 4: AddTerm(&head2, &curr2); break;
			case 5: AddPoly(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n"); break;
		}
	} while (n != 0);
}