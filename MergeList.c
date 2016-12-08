//BUGGY PROGRAM!!


#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;
struct node *curr1 = NULL;
struct node *curr2 = NULL;

void Print(struct node *head, struct node *curr)
{
	curr = head;
	
	if (curr == NULL)
		printf("Linked List is Empty.");
	
	else
	{
		printf("The Equation of Polynomial is:\n");
		
		while (curr)
		{
			printf("%d ", curr->data);
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
	
	printf("Enter Data: ");
	scanf("%d", &(*curr)->data);
	
	if (*head == NULL)
		*head = *curr;
	
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		
		temp->next = *curr;
	}
	
	(*curr)->next = NULL;
	
	Print(*head, *curr);
}

void Merge()
{
	struct node *temp = NULL;
	curr1 = head1;
	curr2 = head2;
	
	while (curr1 && curr2)
	{
		if (curr1->data > curr2->data)
		{
			temp = curr2->next;
			curr2->next = curr1;
			curr2 = temp;
		}
		
		else if (curr1->data < curr2->data)
		{
			temp = curr1->next;
			curr1->next = curr2;
			curr1 = temp;
		}
		
		else
		{
			temp = curr1->next;
			curr1->next = curr2;
			curr1 = curr1->next;
			curr2 = curr2->next;
			curr1->next = temp;
			curr1 = temp;
		}
	}
	
	if (curr1 == NULL)
		Print(head1, curr1);
	else
		Print(head2, curr2);			
}

int main()
{
	int n;
	
	do
	{
		printf("1. Print 1st Linked List\n");
		printf("2. Print 2nd Linked List\n");
		printf("3. Add Terms to 1st Linked List\n");
		printf("4. Add Terms to 2nd Linked List\n");
		printf("5. Merge Linked Lists in Ascending Order\n");
		printf("0. Exit\n");
		printf("Enter Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(head1, curr1); break;
			case 2: Print(head2, curr2); break;
			case 3: AddTerm(&head1, &curr1); break;
			case 4: AddTerm(&head2, &curr2); break;
			case 5: Merge(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}