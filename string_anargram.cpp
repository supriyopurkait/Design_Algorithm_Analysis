#include<stdio.h>
#include<string.h>

int main() {
	char str[] = "heart";
	char str2[] = "earth";
	int len = strlen(str);
	int len2=strlen(str2);
	int count=0;

	if(len==len2)
	{
		for (int i = 0; i < len; i++) 
	{
		for(int j = 0; j < len2;j++)
		{
			if(str[i]==str2[j])
			{
				count++;
			}
		}
	}
	}
	if((count==len)&&(count==len2))
	{
		printf("anargram");
	}
	else
	{
		printf("not anargram");
	}

	return 0;
}

