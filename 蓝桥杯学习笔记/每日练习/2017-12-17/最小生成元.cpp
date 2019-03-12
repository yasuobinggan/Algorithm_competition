#include<stdio.h>
#define max 10
int main()
{
	int n;
	int i,m,sum;
	int t[max],j,k;
	while(scanf("%d",&n)==1)
	for(i=1;i<n;i++)
	{
		m=sum=i;
		j=0;
		while(m>0)
		{
			t[j]=m%10;
			m/=10;
			j++;
		}
		for(k=0;k<j;k++)
		{
			sum+=t[k];
		}
		if(sum==n)
		{
			printf("%d",i);
		}
	}
	
	return 0;
 } 
