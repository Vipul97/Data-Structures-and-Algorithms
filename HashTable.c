#include <stdio.h>
#define m 7

void Print(int A[])
{
	int i;
	
	for (i = 0; i <= m; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}


int Hash(int key)
{
	return key%m;
}

void Insert(int A[])
{
	int key;
	
	printf("Enter Key: ");
	scanf("%d", &key);
	
	int i = 0;
	
	do
	{
		int j = Hash(key);
		
		if (A[j+i] == -1)
		{
			A[j+i] = key;
			Print(A);
			return;
		}
		
		i++;
	} while (i <= m);
	
	printf("Hash Table Overflow.\n");
}

int main()
{
	int n, i, A[m];
	
	for (i = 0; i <= m; i++)
		A[i] = -1;
	
	do
	{
		printf("1. Insert Key in Hashtable\n");
		printf("0. Exit\n");
		printf("Input: ");
		scanf("%d", &n);
		
		switch (n)
		{
			case 1: Insert(A); break;
			case 0: break;
			default: printf("Invalid Input. Try Again.\n");
		}
	} while (n != 0);
}