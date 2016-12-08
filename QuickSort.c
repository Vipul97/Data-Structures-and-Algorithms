#include <stdio.h>

void Print(int A[], int n)
{
	int i, j;
	
	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

/*int Partition(int A[], int p, int r)
{
	int x = A[r];
	int i = p-1;
	int j;
	
	for (j = p; j < r-1; j++)
		if(A[j] <= x)
		{
			i++;
			
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
		
	int t = A[i+1];
	A[i+1] = A[r];
	A[r] = t;
	
	Print(A, r);
	
	return i+1;
}*/

/* int Partition(int A[], int p, int r)
{
	int x = A[p];
	int i = p-1;
	int j = r+1;
	
	while (1)
	{
		do
			j--;
		while (A[j] <= x);
		
		do
			i++;
		while (A[i] >= x);
		
		if (i < j)
		{
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
		
		else
			return j;
	}
} */

int Partition(int A[], int p, int q)
{
	int i = p-1;
	int j = q+1;
	int pv = q;
	//int mid = (p+(q-p))/2;
	//int pv = mid;
	

	while (1)
	{
		do
		{
			i++;
		} while (A[i] <= A[pv] && (i < j));
		
		do
		{
			j--;
		} while (A[j] >= A[pv] && (i < j));
		
		if (i < j)
		{
			int t = A[i];
			A[i] = A[j];
			A[j] = t;
		}
		
		else
			break;
	}
	
	int t = A[pv];
	A[pv] = A[j];
	A[j] = t;
	
	return j;
}

void QuickSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(A, p, r);
		QuickSort(A, p, q-1);
		QuickSort(A, q+1, r);
	}
	
	Print(A, r);
}

int main()
{
	int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	
	QuickSort(A, 0, 9);
}