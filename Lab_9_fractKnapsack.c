#include <stdio.h>

int main() {
    int weight[50], profit[50], capacity, n, i, j;
    float pTOw[50], totalValue = 0.0, temp;

    printf("Enter the number of items: ");
    scanf("%d", &n);   

    for (i = 0; i < n; i++) {
        printf("item[%d] : Weight and Profit = ", i + 1);
        scanf("%d %d", &weight[i], &profit[i]);
    } 

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    for (i = 0; i < n; i++) {
        pTOw[i] = (float)profit[i] / weight[i];
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (pTOw[i] < pTOw[j]) {
                temp = pTOw[j];
                pTOw[j] = pTOw[i];
                pTOw[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = (int)temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = (int)temp;
            }
        }
    }

    printf("\nItems included in the knapsack:\n");
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            printf("100%% of item %d (Profit: %d, Weight: %d)\n", i + 1, profit[i], weight[i]);
            totalValue += profit[i];
            capacity -= weight[i];
        } else {
            printf("%.1f%% of item %d (Profit: %d, Weight: %d)\n", 
                   ((float)capacity / weight[i]) * 100, i + 1, profit[i], weight[i]);
            totalValue += pTOw[i] * capacity;
            break;
        }
    }

    printf("\nMaximum profit = %.2f\n", totalValue);
    return 0;
}

