#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void maxheapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && a[l] > a[largest])
        largest = l;

    if (r <= n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        maxheapify(a, n, largest);
    }
}

void heapsort(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxheapify(a, n, i);
    }
    for (int i = n; i >= 1; i--) {
    	
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        maxheapify(a, i - 1, 1);
    }
}

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Given array is \n");
    printArray(arr, n);

    heapsort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

