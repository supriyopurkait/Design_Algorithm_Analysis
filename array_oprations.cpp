#include<stdio.h>
#include<stdlib.h>
int n,a[100],count=0;
int insert_f();
int display();
int insert_l();
int insert_any();

int options()
{
	int opt;
	printf("enter options:\n1 for insert in first\n2for insert in last\n3 for insert in any\n4 for delete in first\n5 delete in last\n6 for display\n7 for sort\n8 exit\n");

	while(1)
	{
		printf("\nenter choice:\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: insert_f();
					break;
			case 2: insert_l();
					break;
			case 3: insert_any();
					break;
	/*		case 4: delete_f();
					break;
			case 5: delete_l();
					break;
			case 6: delete_any();
					break;
		*/			
			case 7: display();
					break;
		//	case 8: sort();
		//			break;
			case 8: exit(0);
					break;
			default:printf("\nwrong input\n");
		}
	}
}
int insert_f()
{
	int value=0;
	
	if(count<n-1)
	{
		printf("\nenter value:\n");
		scanf("%d",&value);
		for(int i=n; i>=0;i--)
		{
			a[i+1]=a[i];
		}
		a[0]=value;
		++count;
		//printf("successful");
		return 0;
	}
	else
	{
		printf("\nnot possible array is full\n");
	}
	
}
int insert_l()
{
	int value=0;
	
	if((count<n)||(a[n]==0))
	{
		printf("\nenter value:\n");
		scanf("%d",&value);
		a[n-1]=value;
		++count;
		//printf("successful");
		return 0;
	}
	else
	{
		printf("\nnot possible array is full\n");
	}
	
}
int insert_any()
{
	int value=0,pos=0;
	
	if(count<n)
	{
		printf("\nenter position:\n");
		scanf("%d",&pos);
		if(pos<n)
		{
			printf("\nenter value:\n");
			scanf("%d",&value);
			for(int i=pos; i<n;i++)
			{
				a[i+1]=a[i];
			}
			a[pos]=value;
			++count;
			//printf("successful");
			return 0;
		}
		else
		printf("wrong position input");
	}
	else
	{
		printf("\nnot possible array is full\n");
	}
	
}
int display()
{
	printf("values are:\n");
	for(int i=0;i<n;i++)
	{
		printf("a[%d]:%d\t",i,a[i]);
	}
	return 0;
}
main()
{
	printf("enter the array size:\n");
	scanf("%d",&n);
	options();
	return 0;
}
