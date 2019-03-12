#include<stdio.h>
#define max_l 10005
int a[max_l];
int s(int m)
{
	int sum=0,i;
	for(i=1;i<m;i++)
	{
		if(m%i==0)
			sum+=i;	
	}
	return sum;
}
int main()
{
	int i;
	int T,n,j;
	for(i=0;i<max_l;i++)
		a[i]=s(i);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(j=0;j<max_l;j++)
		{
			if(a[j]==n)
			{
				printf("no\n");
				break;	
			}	
		}
		if(j==max_l)
			printf("yes\n");	
	}
	return 0;
} 