#include <stdio.h>

void LinSearch(int A[], int n, int e)
{
	int i, f = 0;

	for (i = 0; i < n; i++)
		if (e == A[i])
		{
			f = 1;
			break;
		}

	if (f == 1)
		printf("Found.\n");
	else
		printf("Not Found.\n");
}

void BinSearch(int A[], int high, int v)
{
	int low = 0, f = 0;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (A[mid] == v)
		{
			f = 1;
			break;
		}

		if (A[mid] < v)
			low = mid + 1;
		else
			high = mid - 1;
	}

	if (f == 1)
		printf("Found.\n");
	else
		printf("Not Found.\n");
}

int main()
{
	int n;

	do
	{

		int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int num;

		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("0. Exit\n");
		printf("Enter Input: ");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			printf("Enter Number to Search: ");
			scanf("%d", &num);
			LinSearch(A, 10, num);
			break;
		case 2:
			printf("Enter Number to Search: ");
			scanf("%d", &num);
			BinSearch(A, 10, num);
			break;
		case 0:
			break;
		default:
			printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
