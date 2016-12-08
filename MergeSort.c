#include <stdio.h>

int temp[10];

void Print(int A[], int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

void Merge(int A[], int p, int m, int q)
{
	int i = p, j = m+1, k = p;

	while (i <= m && j <= q)
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];

	while (i <= m)
		temp[k++] = A[i++];
	
	while (j <= q)
		temp[k++] = A[j++];
	
	for (i = p; i <= q; i++)
		A[i] = temp[i];
}

void MergeSort(int A[], int p, int q)
{
	if (p < q)
	{
		int m = (p+q)/2;
		
		MergeSort(A, p, m);
		MergeSort(A, m+1, q);
		Merge(A, p, m, q);
	}
}

int main()
{
	int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	
	Print(A, 10);
	MergeSort(A, 0, 9);
	Print(temp, 10);
}