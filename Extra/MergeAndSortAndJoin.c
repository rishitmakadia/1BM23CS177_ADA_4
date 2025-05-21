#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // pointer for nums1
    int j = n - 1;        // pointer for nums2
    int k = m + n - 1;    // pointer for placement in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // If any elements remain in nums2 (nums1's are already in place)
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    printf("Merged Array: ");
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
