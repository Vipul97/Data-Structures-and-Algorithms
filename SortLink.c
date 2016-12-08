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
	
	while (curr)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
	
	printf("\n");
}
	
void Sort()
{
	struct node *temp = NULL;
	
	curr = head;
	
	while (curr->next != NULL)
	{
		struct node *max = curr;
		
		temp = curr->next;
		
		while (temp != NULL)
		{
			if (temp->data > max->data)
				max = temp;

			temp = temp->next;
		}
		
		int t = curr->data;
		curr->data = max->data;
		max->data = t;
		
		curr = curr->next;
	}
	
	Print();
	
	curr = head;
	
	while (curr->next != NULL)
		curr = curr->next;
	
	printf("Min Value = %d\n", curr->data);
}

int main()
{
	head = (struct node*)malloc(sizeof(struct node));
	struct node *temp = head;
	
	printf("Enter Values: ");
	scanf("%d", &head->data);
	
	int i;
	
	for (i = 0; i < 9; i++)
	{
		curr = (struct node*)malloc(sizeof(struct node));
		
		if (curr == NULL)
		{
			printf("Error");
			return 0;
		}
		
		scanf("%d", &curr->data);
		
		temp->next = curr;
		temp = curr;
	}
	
	temp->next = NULL;
	
	Print();
	Sort();	
}