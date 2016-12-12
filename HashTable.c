#include <stdio.h>
#define m 7
#define h(k, i) (k + i) % m

void Print(int T[])
{
	int i;

	for (i = 0; i < m; i++)
		printf("%d ", T[i]);

	printf("\n");
}

void HashInsert(int T[], int k)
{
	int i = 0;

	do
	{
		int j = h(k, i);

		if (T[j] == -1)
		{
			T[j] = k;
			return;
		}

		i++;
	} while (i != m);

	printf("Hash Table Overflow.\n");
}

int HashSearch(int T[], int k)
{
	int i = 0, j;

	do
	{
		j = h(k, i);

		if (T[j] == k)
		{
			printf("Key found.\n");
			return j;
		}

		i++;
	} while (T[j] != -1 && i != m);

	printf("Key not found.\n");
}

int main()
{
	int n, i, k;
	int T[m];

	for (i = 0; i <= m; i++)
		T[i] = -1;

	do
	{
		printf("1. Insert Key in Hash Table\n");
		printf("2. Search Key in Hash Table\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			printf("Enter Key: ");
			scanf("%d", &k);
			HashInsert(T, k);
			Print(T);
			break;
		case 2:
			printf("Enter Key: ");
			scanf("%d", &k);
			HashSearch(T, k);
		case 0:
			break;
		default:
			printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}
