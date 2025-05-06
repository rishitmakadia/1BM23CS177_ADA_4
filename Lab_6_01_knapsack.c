#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int i, w;
    int dp[n+1][capacity+1];

    // Build table dp[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i-1] <= w)
                dp[i][w] = max(values[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int values[n], weights[n];

    for (int i = 0; i < n; i++) {
        printf("Item %d - Value & Weight: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    int maxValue = knapsack(capacity, weights, values, n);
    printf("Maximum value in Knapsack = %d\n", maxValue);

    return 0;
}
