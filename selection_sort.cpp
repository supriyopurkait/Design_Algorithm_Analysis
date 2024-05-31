#include<stdio.h>
void selection_sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			min=j;
		}
		int temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
}
int main()
{
	printf("enter the size of the array:");
	int n=0;
	scanf("%d",&n);
	int arr[n];
	printf("\nenter the array element:\n");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,n);
	printf("sorted array is:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
}
