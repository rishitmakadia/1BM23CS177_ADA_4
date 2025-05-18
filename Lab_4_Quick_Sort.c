#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000000

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int a[], int low, int high){
    int pivot = a[high];
    int i=low-1;
    for (int j=low; j< high; j++){
        if (a[j]<pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int par = partition(arr, low, high);
        quickSort(arr, low, par-1);
        quickSort(arr, par + 1, high);
        
    }
}
void printArray(int arr[], int no){
    for (int i=0; i<no; i++)
    printf(" %d ", arr[i]);
    printf("\n");
}

void main(){
    int N;
    printf("Enter Size of Array: ");
    scanf("%d", &N);
    int array[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        array[i] = rand(); 
    }

    printf("Original Array: ");
    printArray(array, N);

    clock_t start_time = clock();
    quickSort(array, 0, N - 1);
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");
    printArray(array, N);
    printf("Time taken to sort: %.10f seconds\n", time_taken);
}