#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;
struct node* curr = NULL;

void Print()
{
    curr = front;

    if (curr == NULL)
        printf("Circular Queue is Empty.");

    else
        do {
            printf("%d ", curr->data);
            curr = curr->next;
        } while (curr != front);

    printf("\n");
}

void Enqueue()
{
    curr = (struct node*)malloc(sizeof(struct node));

    if (curr == NULL) {
        printf("Queue Overflow.\n");
        return;
    }

    printf("Enter Data: ");
    scanf("%d", &curr->data);

    if (rear == NULL)
        front = curr;

    else
        rear->next = curr;

    rear = curr;
    rear->next = front;

    Print();
}

void Dequeue()
{
    struct node* temp = NULL;

    if (front == NULL) {
        printf("Queue Underflow.\n");
        return;
    }

    temp = front;

    if (front == rear)
        front = rear = NULL;

    else {
        front = front->next;
        rear->next = front;
    }

    temp->next = NULL;
    free(temp);

    Print();
}

int main()
{
    int n;

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
            Enqueue();
            break;
        case 3:
            Dequeue();
            break;
        case 0:
            break;
        default:
            printf("Invalid Input. Try Again.\n");
        }
    } while (n != 0);
}
