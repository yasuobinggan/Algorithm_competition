#include<stdio.h>
#include<stdlib.h>
#define max_length 1000
int main()
{
	int n;
	int a[max_length];
	int max=0;
	int sum=0;
	while(scanf("%d",&n)==1)
	{
		max=sum=0;
		for(int i=0;i<n;i++)
		{
			a[i]=0;
			scanf("%d",&a[i]);
			if(a[i]>max)
				max=a[i];
		}
		for(int i=0;i<n;i++)
			sum+=max-a[i];
		printf("%d\n",sum);	
	}
	return 0;
}