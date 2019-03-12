#include<stdio.h>
#define max1 10
int max(int a[],int n,int m)
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
	int n,m,a[max1];
	int i;
	printf("输入数组长度和分组长度:\n");
	scanf("%d%d",&n,&m);
	printf("输入数据:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("%d",max(a,n,m));
	return 0;
 } 
