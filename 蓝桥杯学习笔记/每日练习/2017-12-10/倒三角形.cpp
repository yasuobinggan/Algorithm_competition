#include<stdio.h>
int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(i=n-1;i>=0;i--)
	{
		for(j=1;j<=n-1-i;j++)
		{
			printf(" ");
		}
		for(j=1;j<=i*2+1;j++)
		{
			printf("#");
		}
		printf("\n");
	}
	return 0;
 } 
