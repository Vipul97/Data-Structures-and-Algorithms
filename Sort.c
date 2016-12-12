#include <stdio.h>

void Print(int A[], int n)
{
	int i;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);

	printf("\n");
}

void BubbleSort(int A[], int n)
{
	int i, j;

	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (A[j] > A[j + 1])
			{
				int t = A[j];
				A[j] = A[j + 1];
				A[j + 1] = t;
			}
}

void SelectionSort(int A[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
	{
		int min = i;

		for (j = i + 1; j < n; j++)
			if (A[j] < A[min])
				min = j;

		int t = A[i];
		A[i] = A[min];
		A[min] = t;
	}
}

void InsertionSort(int A[], int n)
{
	int i, j;

	for (j = 1; j < n; j++)
	{
		int key = A[j];
		i = j - 1;

		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}

		A[i + 1] = key;
	}
}

void Merge(int A[], int p, int q, int r)
{
	int i = p, j = q + 1, k = p;
	int temp[10];

	while (i <= q && j <= r)
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];

	while (i <= q)
		temp[k++] = A[i++];

	while (j <= r)
		temp[k++] = A[j++];

	for (i = p; i <= r; i++)
		A[i] = temp[i];
}

void MergeSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;

		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p - 1;
	int j;

	for (j = p; j < r; j++)
		if (A[j] <= x)
		{
			i++;

			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}

	int t = A[i + 1];
	A[i + 1] = A[r];
	A[r] = t;

	return i + 1;
}

void Quicksort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		Quicksort(A, p, q - 1);
		Quicksort(A, q + 1, r);
	}
}

int main()
{
	int n;

	do
	{
		int A[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

		printf("1. Bubble Sort\n");
		printf("2. Selection Sort\n");
		printf("3. Insertion Sort\n");
		printf("4. Merge Sort\n");
		printf("5. Quicksort\n");
		printf("0. Exit\n");
		printf("Enter Input: ");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			BubbleSort(A, 10);
			Print(A, 10);
			break;
		case 2:
			SelectionSort(A, 10);
			Print(A, 10);
			break;
		case 3:
			InsertionSort(A, 10);
			Print(A, 10);
			break;
		case 4:
			MergeSort(A, 0, 9);
			Print(A, 10);
			break;
		case 5:
			Quicksort(A, 0, 9);
			Print(A, 10);
			break;
		case 0:
			break;
		default:
			printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
