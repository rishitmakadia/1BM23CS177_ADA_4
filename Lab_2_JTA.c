#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT_TO_RIGHT true
#define RIGHT_TO_LEFT false

// Function to get the position of the mobile integer
int searchArr(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
            return i + 1;
    return -1;
}

// Function to get the largest mobile integer
int getMobile(int a[], bool dir[], int n) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
        if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
    return mobile;
}

// Function to print one permutation and update the array
void printOnePerm(int a[], bool dir[], int n) {
    int mobile = getMobile(a, dir, n);
    if (mobile == 0) return;

    int pos = searchArr(a, n, mobile) - 1;
    // Note: We use a[pos] - 1 as index into dir[], because dir[] stores directions for the values (1 to n), not positions.
    if (dir[a[pos] - 1] == RIGHT_TO_LEFT)
        // Swap with the left element
        {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;
        }
    else if (dir[a[pos] - 1] == LEFT_TO_RIGHT)
        // Swap with the right element
        {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;
        }

    // After swapping, change the directions of all elements greater than mobile
    for (int i = 0; i < n; i++) {
        if (a[i] > mobile) {
            dir[a[i] - 1] = !dir[a[i] - 1];
        }
    }

    // Print current permutation
    for (int i = 0; i < n; i++)
        printf("%d", a[i]);
    printf(" ");
}

// Factorial function
int fact(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

// Function to print all permutations using Johnson-Trotter algorithm
void printPermutation(int n) {
    int a[n];
    bool dir[n];

    // Initialize the array and direction
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = RIGHT_TO_LEFT;
        printf("%d", a[i]);
    }
    printf(" ");

    // Generate and print all permutations
    for (int i = 1; i < fact(n); i++) {
        printOnePerm(a, dir, n);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printPermutation(n);
    return 0;
}
