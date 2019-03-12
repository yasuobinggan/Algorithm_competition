#include<stdio.h>
int sum=0;
int num(int n,int n1)//n1为分成几个子集 
{
	if(n1==1||n<=n1)
	{
		return 1;
		//return sum;
	}	
	return num(n-1,n1-1)+n1*num(n-1,n1);
}
int main()
{
	int n;int n1;
	int a[100],i;
	int r=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		r+=num(n,a[i]);
	}
	printf("%d",r);
	return 0;
 } 
