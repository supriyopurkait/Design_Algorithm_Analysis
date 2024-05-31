#include<stdio.h>
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
	printf("enter the array element want to serch:");
	int hold=0;
	scanf("%d",&hold);
	for(int idk=0;idk<n;idk++)
	{
		if(arr[idk]==hold)
		{
			printf("element found.\nIdk no %d element=%d",idk,arr[idk]);
			break;
		}
	}


}
