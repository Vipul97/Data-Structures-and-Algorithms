#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
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
		while (curr)
		{
			printf("%d ", curr->data);
			curr = curr->next;
		}
	
	printf("\n");
}

void InsertStart()
{
	curr = (struct node*)malloc(sizeof(struct node));
	
	if (curr == NULL)
	{
		printf("Error.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%d", &curr->data);
	
	curr->prev = NULL;
	
	if (head == NULL)
	{
		head = curr;
		curr->next = NULL;
	}
	
	else
	{
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	
	Print();
}

void InsertEnd()
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
		curr->prev = NULL;
	}
	
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
	
		temp->next = curr;
		curr->prev = temp;
	}
	
	curr->next = NULL;
	
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
		curr->prev = NULL;
		curr->next = NULL;
	}

	else
	{
		printf("Enter Position to Insert Node: ");
		scanf("%d", &k);
		
		while (i < k && temp1 != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->next;
			i++;
		}
		
		if (temp2 == head)
		{
			curr->prev = NULL;
			curr->next = head;
			head->prev = curr;
			head = curr;
		}
		
		else
		{
			curr->prev = temp2;
			curr->next = temp1;
			temp2->next = curr;
			
			if (temp1 != NULL)
				temp1->prev = curr;
		}
	}
	
	Print();
}

void DeleteStart()
{
	struct node *temp = head;
	
	if (head != NULL)
	{
		head = head->next;
		temp->next = NULL;
		
		if (head != NULL)
			head->prev = NULL;
		
		free(temp);
	}
	
	Print();
}

void DeleteEnd()
{
	struct node *temp = head;
	curr = head;
	
	if (head != NULL)
	{
		while (temp->next != NULL)
		{
			curr = temp;
			temp = temp->next;
		}
		
		curr->next = NULL;
		temp->prev = NULL;
		
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
		
		while (i < k && temp->next != NULL)
		{
			curr = temp;
			temp = temp->next;
			i++;
		}
		
		if (temp == head)
			head = head->next;
		
		curr->next = temp->next;
		
		if (head != NULL)
			temp->next->prev = curr;
		
		temp->prev = NULL;
		
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
		printf("3. Insert at End\n");
		printf("4. Insert at Kth\n");
		printf("5. Delete at Start\n");
		printf("6. Delete at End\n");
		printf("7. Delete at Kth\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(); break;
			case 2: InsertStart(); break;
			case 3: InsertEnd(); break;
			case 4: InsertKth(); break;
			case 5: DeleteStart(); break;
			case 6: DeleteEnd(); break;
			case 7: DeleteKth(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}