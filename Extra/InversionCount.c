#include <stdio.h>

// Function to merge two halves and count inversions
int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray
    int j = mid + 1;  // right subarray
    int k = left;
    int inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);  // All elements from i to mid form inversion with arr[j-1]
        }
    }

    // Copy remaining elements
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

// Recursive function to count inversions
int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (left < right) {
        mid = (left + right) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

// Wrapper function
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

// Main
int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = countInversions(arr, n);
    printf("Inversion Count: %d\n", result);  // Output: 6
    return 0;
}
