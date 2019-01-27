#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int Knapsack(int n, int W, int val[], int wt[])
{
    int K[n + 1][W + 1];
    int i, w;

    for (i = 0; i <= n; i++)
        K[i][0] = 0;

    for (w = 0; w <= W; w++)
        K[0][w] = 0;

    for (i = 1; i <= n; i++)
        for (w = 0; w <= W; w++) {
            if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }

    return K[n][W];
}

int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int n = 3, W = 50;

    printf("%d\n", Knapsack(n, W, val, wt));
}
