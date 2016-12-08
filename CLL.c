#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;

void Print()
{
	curr = head;
	
	if (curr == NULL)
		printf("Linked List is Empty.");
	
	else
		do
		{
			printf("%d ", curr->data);
			curr = curr->next;
		} while (curr != head);
	
	printf("\n");
}

void InsertStart()
{
	struct node *temp = head;
	curr = (struct node*)malloc(sizeof(struct node));
	
	if (curr == NULL)
	{
		printf("Error.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &curr->data);
	
	if (head == NULL)
	{
		head = curr;
		curr->next = head;
	}
	
	else
	{
		while (temp->next != head)
			temp = temp->next;

		temp->next = curr;
		curr->next = head;
		head = curr;
	}
	
	Print();
}

void InsertKth()
{
	int i = 0, k;
	
	struct node *temp1 = head, *temp2;
	curr = (struct node*)malloc(sizeof(struct node));
	
	if (curr == NULL)
	{
		printf("Error.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &curr->data);

	if (head == NULL)
	{
		head = curr;
		curr->next = head;
	}

	else
	{
		printf("Enter Position to Insert Node: ");
		scanf("%d", &k);
		
		while (i < k)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			i++;
		}
		
		temp2->next = curr;
		curr->next = temp1;
	}
	
	Print();
}

void DeleteStart()
{
	struct node *temp1 = head, *temp2 = head;
	
	if (head != NULL)
	{
		while (temp1->next != head)
			temp1 = temp1->next;

		if (head->next == head)
			head = NULL;

		else
		{
			head = head->next;
			temp1->next = head;
			free(temp2);
		}
	}
	
	Print();
}

void DeleteEnd()
{
	struct node *temp = head;
	curr = head;
	
	if (head != NULL)
	{
		while (temp->next != head)
		{
			curr = temp;
			temp = temp->next;
		}
		
		curr->next = head;
		
		if (temp == head)
			head = NULL;
		else
			free(temp);
	}

	Print();
}

void DeleteKth()
{
	int i = 0, k;
	
	struct node *temp = head;
	curr = head;
	
	if (head != NULL)
	{
		printf("Enter Position of Node to Delete: ");
		scanf("%d", &k);
		
		while (i < k && temp->next != head)
		{
			curr = temp;
			temp = temp->next;
			i++;
		}
		
		if (temp == head)
			head = head->next;
		
		curr->next = temp->next;
		
		if (temp == head)
			head = NULL;
		else
			free(temp);
	}
	
	Print();
}

int main()
{
	int n;
	
	do
	{
		printf("1. Print\n");
		printf("2. Insert at Start\n");
		printf("3. Insert at Kth\n");
		printf("4. Delete at Start\n");
		printf("5. Delete at End\n");
		printf("6. Delete at Kth\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(); break;
			case 2: InsertStart(); break;
			case 3: InsertKth(); break;
			case 4: DeleteStart(); break;
			case 5: DeleteEnd(); break;
			case 6: DeleteKth(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}