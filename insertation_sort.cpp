#include<stdio.h>
void insertion_sort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int key=a[i];
		int j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main()
{
	printf("enter the size of the array:");
	int n=0;
	scanf("%d",&n);
	int arr[n];
	printf("\nenter the arr element:\n");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr,n);
	printf("sorted array is:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
}
