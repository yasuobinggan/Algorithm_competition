#include<stdio.h>
#define max_length 1000
int judge(int a[],int b[],int n)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]!=b[i])
			break;
	if(i==n)
		return 1;
	else
		return 0;
}
int main()
{
	int n,l;//nÕÏ°­Êý,l¹ìµÀ³¤ 
	int k[max_length],s[max_length];
	int tar,i,j;
	while(scanf("%d%d",&n,&l)==2)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&k[i]);
		}
		tar=k[0];
		for(i=0;i<n;i++)
		{	
			k[i]-=tar;
		}
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&s[i]);			
		}
		tar=s[0];
		for(i=0;i<n;i++)
		{
			s[i]-=tar;
		}
		for(i=0;i<n;i++)
		{
			if(judge(k,s,n))
				break;
			for(j=1;j<=n-2;j++)
				k[j]=k[j+1]-k[j];
			k[n-1]=k[n-2]+(l-k[n-1]);
		}
		if(i!=n)
			printf("YES\n");
		else
			printf("NO\n");	
	}	
		
			
	return 0;
} 