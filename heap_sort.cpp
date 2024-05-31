#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;  
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;

    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int c = 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i >= 1; i--) {
        printf("\nStep %d:\n", c);
        printArray(arr, n);
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        n--;
        maxHeapify(arr, n, 0);
        printArray(arr, n);
        c++;
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

    heapSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
