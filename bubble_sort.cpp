//best case time complexity:O(n), worst case time complexity:n^2 , avg case time complexity:n^2;
#include<stdio.h>
int main()
{
	int n,min=0;
	printf("\nenter size of array:\n");
	scanf("%d",&n);
	int a[n];
	printf("\nenter array element:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int flag=0,count=0;
	for(int i=0;i<n-1;i++)
	{
		flag=0,count=0;
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				flag++;
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}
			count++;
		}
		printf("%d pass no,no of swap=%d,number of comparison=%d\n",i+1,flag,count);
		if(flag==0)
		break;
	}
	printf("\narray elements are:\n");
	for(int i=0;i<n;i++)
	{
		printf("[%d]",a[i]);
	}
}
