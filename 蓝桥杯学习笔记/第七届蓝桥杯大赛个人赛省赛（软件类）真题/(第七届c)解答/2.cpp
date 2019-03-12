#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<=118;i++)
	{
		for(j=i;j<=118;j++)
		{
			if(((i+j)*(j-i+1))/2==236)
				printf("%d ",i);
		}
	}
	return 0;
}