#include <stdio.h>

void search(int A[], int n, int e)
{
    int i, f = 0;
    
    for (i = 0; i < n; i++)
        if (e == A[i])
            f = 1;
    
    if (f == 1)
        printf("Found.\n");
    else
        printf("Not Found.\n");
}

int main()
{
    int n;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Enter number to search: ");
    scanf("%d", &n);
    search(A, 10, n);
}