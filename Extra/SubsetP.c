#include <stdio.h>

#define MAX 100

int subset[MAX];  // To store the current subset

// Backtracking function to find subsets
void subsetSum(int arr[], int n, int index, int target, int currSum) {
    if (currSum == target) {
        printf("Subset found: ");
        for (int i = 0; i < index; i++)
            printf("%d ", subset[i]);
        printf("\n");
        return;
    }

    // If current sum exceeds target or no elements left
    if (currSum > target || n == 0)
        return;

    // Include the current element
    subset[index] = arr[0];
    subsetSum(arr + 1, n - 1, index + 1, target, currSum + arr[0]);

    // Exclude the current element
    subsetSum(arr + 1, n - 1, index, target, currSum);
}

int main() {
    int arr[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 35;

    printf("Subsets of sum %d are:\n", target);
    subsetSum(arr, n, 0, target, 0);

    return 0;
}