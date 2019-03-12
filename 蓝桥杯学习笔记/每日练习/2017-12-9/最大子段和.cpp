#include<stdio.h>
#define max1 10
/*
int max(int a[],int n)
{
	int i,max=0;
	int temp=0;
	for(i=0;i<n;i++)
	{
		//temp=max;
		temp+=a[i];
		if(temp>max)
			max=temp;
		else if(a[i]>max)
		{
			max=a[i];
			temp=a[i];
		}
			
	}
	return max;
}
*/
int max(int a[],int n)
{
	int i,max=0,temp=0;
	for(i=0;i<n;i++)
	{
		if(temp>0)
			temp+=a[i];
		else
			temp=a[i];
		if(temp>max)
			max=temp;
	}
	return max;
}
int main()
{
	int n,a[max1];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d",max(a,n));
	return 0;
 } 
