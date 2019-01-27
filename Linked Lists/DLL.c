#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
struct node* curr = NULL;

void Print()
{
    curr = head;

    if (curr == NULL)
        printf("Linked List is Empty.");

    else
        while (curr) {
            printf("%d ", curr->key);
            curr = curr->next;
        }

    printf("\n");
}

struct node* ListSearch(int k)
{
    struct node* x = head;

    while (x != NULL && x->key != k)
        x = x->next;

    return x;
}

void ListInsert(struct node* x)
{
    x->next = head;

    if (head != NULL)
        head->prev = x;

    head = x;
    x->prev = NULL;
}

void ListDelete(struct node* x)
{
    if (x->prev != NULL)
        x->prev->next = x->next;
    else
        head = x->next;

    if (x->next != NULL)
        x->next->prev = x->prev;
}

int main()
{
    int n, k;

    do {
        printf("1. Print\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("0. Exit\n");
        printf("Input: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            Print();
            break;
        case 2:
            printf("Enter Key: ");
            scanf("%d", &k);
            curr = (struct node*)malloc(sizeof(struct node));
            curr->key = k;
            ListInsert(curr);
            Print();
            break;
        case 3:
            printf("Enter Key: ");
            scanf("%d", &k);

            if (ListSearch(k) == NULL) {
                printf("Key not found.\n");
                break;
            }

            ListDelete(ListSearch(k));
            Print();
            break;
        case 0:
            break;
        default:
            printf("Invalid Input. Try Again.\n");
        }
    } while (n != 0);
}
