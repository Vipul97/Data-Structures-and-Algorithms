#include <stdio.h>

void Print(int A[], int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

void BubbleSort(int A[], int n)
{
	int i, j;
	
	for (i = 1; i < n; i++)
		for (j = 0; j < n-i; j++)
			if (A[j] > A[j+1])
			{
				int t = A[j];
				A[j] = A[j+1];
				A[j+1] = t;
			}
			
	Print(A, 10);
}

void SelectionSort(int A[], int n)
{
	int i, j;
	
	for (i = 0; i < n-1; i++)
	{
		int min = i;
		
		for (j = i+1; j < n; j++)
			if (A[j] < A[min])
				min = j;
			
		int t = A[i];
		A[i] = A[min];
		A[min] = t;
	}
	
	Print(A, 10);
}

void InsertionSort(int A[], int n)
{
	int i, j;
	
	for (j = 1; j < n; j++)
	{
		i = j-1;
		int key = A[j];
		
		while (i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i--;
		}
		
		A[i+1] = key;
	}
	
	Print(A, 10);
}

int main()
{
	int n;
	
	do
	{
		int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		
		printf("1. Bubble Sort\n");
		printf("2. Selection Sort\n");
		printf("3. Insertion Sort\n");
		printf("0. Exit\n");
		printf("Enter Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: BubbleSort(A, 10); break;
			case 2: SelectionSort(A, 10); break;
			case 3: InsertionSort(A, 10); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}