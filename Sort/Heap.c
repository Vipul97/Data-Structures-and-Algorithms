#include <stdio.h>
#define Parent(i) i / 2
#define Left(i) 2 * i + 1
#define Right(i) 2 * i + 2
#define HeapMaximum(A) A[0]

int size = -1, length = 10;

void Print(int A[], int n)
{
    int i;

    for (i = 0; i <= length && A[i] != -1; i++)
        printf("%d ", A[i]);

    printf("\n");
}

void MaxHeapify(int A[], int i)
{
    int l = Left(i);
    int r = Right(i);
    int largest;

    if (l <= size && A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= size && A[r] > A[largest])
        largest = r;

    if (largest != i) {
        int t = A[i];
        A[i] = A[largest];
        A[largest] = t;

        MaxHeapify(A, largest);
    }
}

void BuildMaxHeap(int A[])
{
    int i;

    size = length;

    for (i = length / 2; i >= 0; i--)
        MaxHeapify(A, i);
}

void Heapsort(int A[])
{
    int i;

    BuildMaxHeap(A);

    for (i = length; i > 0; i--) {
        int t = A[0];
        A[0] = A[i];
        A[i] = t;
        size--;

        MaxHeapify(A, 0);
    }
}

int HeapExtractMax(int A[])
{
    if (size < 0) {
        printf("Heap Underflow.\n");
        return;
    }

    int max = A[0];
    A[0] = A[size];
    size--;

    MaxHeapify(A, 0);

    return max;
}

void HeapIncreaseKey(int A[], int i, int key)
{
    if (key < A[i]) {
        printf("New key is smaller than current key.\n");
        return;
    }

    A[i] = key;

    while (i > 0 && A[Parent(i)] < A[i]) {
        int t = A[i];
        A[i] = A[Parent(i)];
        A[Parent(i)] = t;
        i = Parent(i);
    }
}

void MaxHeapInsert(int A[], int key)
{
    size++;
    A[size] = -1;

    HeapIncreaseKey(A, size, key);
}

int main()
{
    int n, i, A[length], key;

    for (i = 0; i <= length; i++)
        A[i] = -1;

    do {
        printf("1. Print Heap\n");
        printf("2. Build Max Heap\n");
        printf("3. Heapsort\n");
        printf("4. Extract Max\n");
        printf("5. Increase Key\n");
        printf("6. Insert in Max Heap\n");
        printf("0. Exit\n");
        printf("Input: ");
        scanf("%d", &n);

        switch (n) {
        case 1:
            Print(A, length);
            break;
        case 2:
            BuildMaxHeap(A);
            Print(A, length);
            break;
        case 3:
            Heapsort(A);
            Print(A, length);
            break;
        case 4:
            HeapExtractMax(A);
            Print(A, length);
            break;
        case 5:
            printf("Enter Index: ");
            scanf("%d", &i);
            printf("Enter Key: ");
            scanf("%d", &key);
            HeapIncreaseKey(A, i, key);
            Print(A, length);
            break;
        case 6:
            printf("Enter Key: ");
            scanf("%d:", &key);
            MaxHeapInsert(A, key);
            Print(A, length);
            break;
        case 0:
            break;
        default:
            printf("Invalid Input. Try Again.\n");
        }
    } while (n != 0);
}
