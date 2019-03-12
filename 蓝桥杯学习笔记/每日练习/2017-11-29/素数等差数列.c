#include<stdio.h>
#include <limits.h>
typedef struct{
	int a[10];
	int s;
	int e;
};
int flag(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;//素数返回1 
}
/*
int dengcha(int a[10])
{
	int i;
	int sum1,sum2;
	sum1=a[1]-a[0];
	for(i=0;i<=8;i++)
	{
		if((a[i]+sum1)!=a[i+1])
			break;
	}
	if(i==9)//等差数列返回1 
		return 1;
	else
		return 0;
}
int gongcha(int a[10])
{
	return (a[9]-a[8]);
}

int main()
{
	int a[10]={
		1,3,5,7,9,11,13,15,17,19
	};
	printf("%d %d ",dengcha(a),gongcha(a));
	return 0;
}

void operation_a(int a[10])
{
	int i;
	for(i=1;i<=9;i++)
	{
		a[i-1]=a[i];
	}
}
*/
int find(int a[500000],int count,int n)
{
	int i;
	for(i=0;i<count;i++)
	{
		if(n==a[i])
			break;
	}
	if(i==count)
		return 0;
	else
		return 1;//在数组里 
 } 
void printf_a(int a[500000])
{
	int i;
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int min=10000;//标记最小的公差 
	int i,j,k;
	int a[5000];
	int count=0;//标记候选数组长度 
	//int count1=0;//对等差数列计数 
	int d;
	for(i=2;i<=10000;i++)
	{
		if(flag(i))
		{
			a[count]=i;
			count++;
		}
	}
	printf("%d\n",count);
	
	for(i=0;i<count;i++)//a[i]为等差数列头 
	{
		for(j=i+1;j<count;j++)//a[j]-a[i]求公差 
		{
			//count1=0; 
			d=a[j]-a[i];
			for(k=2;k<=9;k++)
			{
				if(!find(a,count,a[i]+k*d))
					break;  
			}
			if(k==10&&(min>d))
				min=d;
		}
	}
	printf("%d",min);
	return 0;
}
/*
int main()//利用移动窗口查找,算法根本上有问题 
{
	int min=10000;
	int i;
	int a[10]; 
	int count=0;
	for(i=2;i<=1000000;i++)//1000000
	{
		if(flag(i))
		{
			
			a[count]=i;
			count++;
			if(count==10)
			{
				if(dengcha(a))
				{
					
					printf_a(a); 
					
					if(gongcha(a)<min)
					{
						min=gongcha(a);
					}
					
				}
				operation_a(a);
				count=9;	
			}
			 
			  a[count]=i;
			  count++;
			  if(count==10)
		}
	}
	//printf("%d",min);
	return 0;
}
*/
