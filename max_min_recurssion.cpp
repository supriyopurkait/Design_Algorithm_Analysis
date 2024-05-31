#include <stdio.h>

void findMaxMin(int arr[], int start, int end, int *max, int *min) {
    if (start == end)
	{
        *max = *min = arr[start];
        return;
    }

    if (start == end - 1)
	{
    	if(arr[start] > arr[end])
    	{
    		*max=arr[start];
    		*min =arr[end];
		}
        else
        {
        	*max=arr[end];
    		*min =arr[start];
		}
        return;
    }

    int mid = (start + end) / 2;
    int leftMax, leftMin, rightMax, rightMin;
    
    findMaxMin(arr, start, mid, &leftMax, &leftMin);
    findMaxMin(arr, mid + 1, end, &rightMax, &rightMin);

	if(leftMax > rightMax)
    	{
    		*max=leftMax;
		}
        else if(leftMax < rightMax)
        {
        	*max=rightMax;
		}
	if(leftMin < rightMin){
		*min=leftMin;
	}
	else if(leftMin > rightMin){
		*min=rightMin;
	}
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max, min;

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}

