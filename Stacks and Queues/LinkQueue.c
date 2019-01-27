#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* curr = NULL;

void Print()
{
    curr = head;

    if (curr == NULL)
        printf("Queue is Empty.");

    else
        while (curr) {
            printf("%d ", curr->key);
            curr = curr->next;
        }

    printf("\n");
}

void Enqueue(struct node* x)
{
    if (tail == NULL)
        head = x;

    else
        tail->next = x;

    tail = x;
    tail->next = NULL;
}

void Dequeue()
{
    struct node* temp = NULL;

    if (head == NULL) {
        printf("Queue Underflow.\n");
        return;
    }

    temp = head;

    if (head == tail)
        head = tail = NULL;
    else
        head = head->next;

    temp->next = NULL;
    free(temp);
}

int main()
{
    int n, k;

    do {
        printf("1. Print Queue\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
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
            Enqueue(curr);
            Print();
            break;
        case 3:
            Dequeue();
            Print();
            break;
        case 0:
            break;
        default:
            printf("Invalid Input. Try Again.\n");
        }
    } while (n != 0);
}
