#include<stdio.h>
int main()
{
	int a,b,c;
	int i;//sum>=10&&sum<=100
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		for(i=10;i<=100;i++)
		{
			if(i%3==a&&i%5==b&&i%7==c)
			{
				printf("%d ",i);
				break;
			}
				
		}
		if(i==101)
			printf("no answer");
	}
	return 0;
}
