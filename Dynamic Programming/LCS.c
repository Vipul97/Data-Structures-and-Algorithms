#include <stdio.h>
#include <string.h>
#define MAX 100

int c[MAX][MAX];
char b[MAX][MAX];

int LCSLength(char X[], char Y[])
{
    int m = strlen(X) + 1;
    int n = strlen(Y) + 1;
    int i, j;

    for (i = 0; i < m; i++)
        c[i][0] = 0;

    for (j = 0; j < n; j++)
        c[0][j] = 0;

    for (i = 1; i < m; i++)
        for (j = 1; j < n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i - 1][j - 1] = '\\';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i - 1][j - 1] = '|';
            } else {
                c[i][j] = c[i][j - 1];
                b[i - 1][j - 1] = '-';
            }
        }
}

void PrintLCS(char b[][MAX], char X[], int i, int j)
{
    if (i == -1 || j == -1)
        return;

    if (b[i][j] == '\\') {
        PrintLCS(b, X, i - 1, j - 1);
        printf("%c", X[i]);
    } else if (b[i][j] == '|')
        PrintLCS(b, X, i - 1, j);
    else
        PrintLCS(b, X, i, j - 1);
}

int main()
{
    char X[] = "ABDBDAB", Y[] = "BDCABA";

    LCSLength(X, Y);
    PrintLCS(b, X, strlen(X) - 1, strlen(Y) - 1);
    printf("\n");
}
