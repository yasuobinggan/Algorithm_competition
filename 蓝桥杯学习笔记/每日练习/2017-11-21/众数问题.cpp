#include<stdio.h>

int Merage(int a[],int left,int right)
{
	int mid;
	mid=left+right;
}

/*
void search(int a[],int n)
{
	int i,j;
	int count=0,max=0;
	int zhongshu=0;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(a[j]==a[i])
				count++;
		}
		if(count>max)
		{
			max=count;
			zhongshu=a[i];
		}
	}
	printf("%d %d",zhongshu,max);
}
*/
int main()
{
	int n,a[n];
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//search(a,n);
	
	return 0;
}
