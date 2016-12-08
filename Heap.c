#include <stdio.h>
#define size 100

int root = -1, n = 0;

void Preorder(int A[], int i)
{
	if (A[i] != -1)
		printf("[%d: %d] ", i, A[i]);
	
	if (2*i + 1 < size)
		Preorder(A, 2*i + 1);
	
	if (2*i + 2 < size)
		Preorder(A, 2*i + 2);
}

void Inorder(int A[], int i)
{
	if (2*i + 1 < size)
		Inorder(A, 2*i + 1);

	if (A[i] != -1)
		printf("[%d: %d] ", i, A[i]);
	
	if (2*i + 2 < size)
		Inorder(A, 2*i + 2);
}

void Postorder(int A[], int i)
{
	if (2*i + 1 < size)
		Postorder(A, 2*i + 1);

	if (2*i + 2 < size)
		Postorder(A, 2*i + 2);
	
	if (A[i] != -1)
		printf("[%d: %d] ", i, A[i]);
	
}

void Insert(int A[])
{
	int data;
	int p;
	
	printf("Enter Data: ");
	scanf("%d", &data);
	
	n++;
	p = n;
	
	while (p > 0)
	{
		if (A[p/2] < data)
		{
			A[p] = A[p/2];
			p /= 2;
		}
		
		else
			break;
	}
	
	printf("A[%d] = %d\n", p, data);
	A[p] = data;
}

void MaxHeapify(int A[], int i)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;
	
	if (l <= n && A[l] > A[i])
		largest = l;

	else
		largest = i;

	if (r <= n && A[r] > A[largest])
		largest = r;
	
	if (largest != i)
	{
		int t = A[i];
		A[i] = A[largest];
		A[largest] = t;
		MaxHeapify(A, largest);
	}

}

void Delete(int A[])
{
	int max = A[0];

	A[0] = A[n];
	A[n] = -1;
	
	MaxHeapify(A, 0);
	
	if (n == 0)
		printf("Heap is Empty.\n");
	
	else
	{
		printf("%d Deleted.\n", max);
		n--;
	}
}

int main()
{
	int n, i, A[size];
	
	for (i = 0; i < size; i++)
		A[i] = -1;
	
	do
	{
		printf("1. Traverse Max Heap in Preorder\n");
		printf("2. Traverse Max Heap in Inorder\n");
		printf("3. Traverse Max Heap in Postorder\n");
		printf("4. Insert Node in Max Heap\n");
		printf("5. Delete Node from Max Heap\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Preorder(A, 0); printf("\n"); break;
			case 2: Inorder(A, 0); printf("\n"); break;
			case 3: Postorder(A, 0); printf("\n"); break;
			case 4: Insert(A); break;
			case 5: Delete(A); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}