#include<stdio.h>
void bubble(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int idk=0;idk<n;idk++)
	{
		printf("index %d:[%d]",idk,a[idk]);
	}
}
int binary(int arr[],int low,int high)
{
	printf("\nenter the array element want to serch:");
	int hold=0;
	scanf("%d",&hold);
	while(low<=high)
	{
		int mid= (low+high)/2;
		if(arr[mid]==hold)
		{
			return mid;
		}
		else if(arr[mid]<hold)
		{
			low=mid+1;
			
		}
		else
		{
			high=mid-1;
			
		}
	}
	return -1;
}
int main()
{
	printf("enter the array size:");
	int n;
	scanf("%d",&n);
	int arr[n];
	printf("enter the array element---\n");
	for(int idk=0;idk<n;idk++)
	{
		printf("enter the array element for index for arr[%d]",idk);
		scanf("%d",&arr[idk]);
	}
	bubble(arr,n);
	int re=binary(arr,0,n);
	(re==-1)?printf("Array element not found"):printf("Array element found:%d",re);
}
