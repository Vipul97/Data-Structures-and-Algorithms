#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
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

struct node *ListSearch(int k)
{
	struct node *x = head;

	while (x != head && x->key != k)
		x = x->next;

	return x;
}

void ListInsert(struct node *x)
{
	struct node *temp = head;

	if (head == NULL)
	{
		head = x;
		x->next = head;
	}

	else
	{
		while (temp->next != head)
			temp = temp->next;

		temp->next = x;
		x->next = head;
		head = x;
	}
}

void ListDelete(int key)
{
	struct node *temp1 = head, *temp2 = head;

	curr = head;

	if (head != NULL)
	{
		while (temp->next != head && temp->key != key)
		{
			curr = temp;
			temp = temp->next;
		}

		if (temp == head)
			head = head->next;

		curr->next = temp->next;

		if (temp == head)
			head = NULL;
		else
			free(temp);
	}
}
}
if (head != NULL)
{
	while (temp1->next != head && temp1->key != key)
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

if (x->prev != NULL)
x->prev->next = x->next;
else
head = x->next;

if (x->next != NULL)
x->next->prev = x->prev;
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
		case 1:
			Print();
			break;
		case 2:
			InsertStart();
			break;
		case 3:
			InsertKth();
			break;
		case 4:
			DeleteStart();
			break;
		case 5:
			DeleteEnd();
			break;
		case 6:
			DeleteKth();
			break;
		case 0:
			break;
		default:
			printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
