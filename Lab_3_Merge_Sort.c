#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
// Sort a given set of N integer elements using Merge Sort
// technique and compute its time taken. Run the program
// for different values of N and record the time taken to sort.

void merge(int a[], int low, int high, int mid);
void mergeSort(int arr[], int low, int high);
void printArray(int arr[], int no);

void merge(int a[], int low, int high, int mid)
{
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= high)
        temp[k++] = a[j++];

    for (int i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
    }
}

void printArray(int arr[], int no)
{
    for (int i = 0; i < no; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    int N;
    printf("Enter Size of Array: ");
    scanf("%d", &N);
    int array[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand(); // Random integers between 0 and 99
    }

    printf("Original Array: ");
    printArray(array, N);

    clock_t start_time = clock();
    mergeSort(array, 0, N - 1);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");
    printArray(array, N);
    printf("Time taken to sort: %.100f seconds\n", time_taken);
}
