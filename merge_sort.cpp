#include <stdio.h>

// Merge function to merge two sorted subarrays
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;    // Size of left subarray
    int n2 = high - mid;       // Size of right subarray
    int left[n1], right[n2];  // Temporary arrays

    // Copy data to temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back into arr[low..high]
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[] and right[] if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Merge sort function
void merge_sort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Recursively sort the two halves
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    merge_sort(a, 0, n - 1);

    printf("Sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

