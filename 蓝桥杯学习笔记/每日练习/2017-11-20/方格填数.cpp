#include<stdio.h>
#include<math.h>
int count=0;
void create_array(int a[12])
{
	int i;
	for(i=0;i<12;i++)
	{
		a[i]=i+1;
	}
}
int dfs(int a[])
{
	int i;
	for(i=0;i<5;i++)
	{
		if(1!=abs(a[i+1]-a[i])||4!=abs(a[i+1]-a[i]))
			return 0;
	}
	return 1;
}
void swap(int &a1,int &a2)
{
	int t;
	t=a1;
	a1=a2;
	a2=t;
}
int rank(int a[],int s,int e)
{
	int i;
	
	if(s==e)//对叶子节点进行显示,记录 
	{
		/*
		for(i=0;i<=e;i++)
		{
			printf("%d\t",a[i]);
		}
		printf("\n");
		*/
		if(dfs(a))
			count++;
	}	
	else
	{
		for(i=s;i<=e;i++)
		{
			swap(a[s],a[i]);
			rank(a,s+1,e);
			swap(a[i],a[s]);
		}
	}
	return count;
}
int amount(int a[12])
{
	int i;
	int r=0;
	for(i=0;i+4<12;i++)
		r+=rank(a,i,i+4);
	return r;
}
int main()
{
	int a[12];
	create_array(a);
	printf("%d",amount(a)); 
	return 0;
 } 
