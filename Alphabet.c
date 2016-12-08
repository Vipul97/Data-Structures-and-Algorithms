#include <stdio.h>
#include <stdlib.h>

struct node
{
	char alpha;
	struct node *next;
};

struct node *head = NULL;
struct node *curr = NULL;
struct node *vowel_head;
struct node *consonant_head;

void Print(struct node *head)
{
	curr = head;
	
	if (curr == NULL)
		printf("Linked List is Empty.");
	
	else
		while (curr)
		{
			printf("%c ", curr->alpha);
			curr = curr->next;
		}

	printf("\n");
}

void Insert()
{
	struct node *temp = head;
	curr = (struct node*)malloc(sizeof(struct node));
	
	if (curr == NULL)
	{
		printf("Error.\n");
		return;
	}
	
	printf("Enter Data: ");
	scanf("%c", &curr->alpha);
	
	if (head == NULL)
		head = curr;
	
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
	
		temp->next = curr;
	}
	
	curr->next = NULL;
	
	Print(head);
}

void DeleteStart()
{
	struct node *temp = head;
	
	if (head != NULL)
	{
		head = head->next;
		free(temp);
	}
	
	Print(head);
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
		
		if (temp == head)
			head = NULL;
		else
			free(temp);
	}
	
	Print(head);
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
		free(temp);
	}
	
	Print(head);
}

void Split()
{
	printf("Given Nodes:\n");
	Print(head);

	struct node *vowel = NULL;
	struct node *consonant = NULL;

	curr = head;

	while (curr)
	{
		if ((curr->alpha == 'A') || (curr->alpha == 'E') ||
			(curr->alpha == 'I') || (curr->alpha == 'O') ||
			(curr->alpha == 'U'))
		{
			if (vowel_head == NULL)
				vowel_head = curr;
			
			else
				vowel->next = curr;
			
			vowel = curr;
		}
		
		else
		{
			if (consonant_head == NULL)
				consonant_head = curr;
			
			else
				consonant->next = curr;
			
			consonant = curr;
		}

		curr = curr->next;
	}

	vowel->next = NULL;
	consonant->next = NULL;
	
	printf("Vowels:\n");
	Print(vowel_head);
	printf("Consonants:\n");
	Print(consonant_head);
}

int main()
{
	int n;
	
	do
	{
		printf("1. Print\n");
		printf("2. Insert\n");
		printf("3. Delete at Start\n");
		printf("4. Delete at End\n");
		printf("5. Delete at Kth\n");
		printf("6. Split Nodes\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Print(head); break;
			case 2: Insert(); break;
			case 3: DeleteStart(); break;
			case 4: DeleteEnd(); break;
			case 5: DeleteKth(); break;
			case 6: Split(); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}