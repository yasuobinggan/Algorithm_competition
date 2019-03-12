#include<stdio.h>

int main()
{
	int i;
	int sum=0;
	for(i=100;i>=1;i--)
		sum+=i;
	printf("%d",sum);
	return 0;
} 