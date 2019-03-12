#include<stdio.h>
#include<stdlib.h>
#define max 100
typedef struct{
	int tar[max];
	int i;
	int j;
}sq;
void create(sq &s)
{
	s.i=s.j=0;
}
void ru(sq &s,int t)
{
	s.tar[s.j]=t;
	s.j=(s.j+1)%max;
}
int chu(sq &s)
{
	int e=s.tar[s.i];
	s.i=(s.i+1)%max;
	return e;
}
void dis(sq s)
{
	int k;
	printf("组合:");
	for(k=s.i;k<=s.j;k++)
		printf("%d ",s.tar[k]);
	printf("\n");
}
/*
void a_group(int c[],int T,int length)//利用循环解决 
{
	int i;int j;
	for(i=length-1;i>=0;i--)
	{
		if(c[i]==T)
			printf("组合:%d\n",c[i]); 
		if(c[i]<T)
		{
			for(j=i;j>=0;j--)
			{
				if(c[j]==T-c[i]||((T-c[i])%c[j]==0))
				{
					printf("组合:%d %d\n",c[i],c[j]);
				}
			}
		}
	}
}
*/
/*
void a_group(int c[],int T,int length)//利用递归解决//length为最大数组下标 
{
	int i;
	if(T>0&&length>=0)
	{
		for(i=length;i>=0;i--)
		{
			if(c[i]<T)
				a_group(c,T-c[i],i-1);
			if(c[i]==T)
			{
				printf("组合:%d \n",c[i]);
				a_group(c,T-c[i],i-1);
			}
			if(T%c[i]==0&&T/c[i]!=1)
			{
				printf("组合:%d*%d \n",T/c[i],c[i]);
				a_group(c,c[i],i-1);
			}	
		}
	}
	
 }
*/ 

void a_group(int c[],int T,int length,sq &s)
{
	int i;
	int j;//控制循环入栈 
	int num;//获取出栈数字 
	if(T>0&&length>=0)
	{
		for(i=length;i>=0&&c[i]>=(T/2);i--)
		{
			if(c[i]<T)
				a_group(c,T-c[i],i-1,s);
			if(c[i]==T)
			{
				//printf("组合:%d \n",c[i]);
				if(s.i==0)
				{
					ru(s,c[i]);
					dis(s);
					a_group(c,T-c[i],i-1,s);
				}
				else
				{
					num=chu(s);
					ru(s,c[i]);
					ru(s,num-c[i]);
					dis(s);
					a_group(c,T-c[i],i-1,s);
				}
			}
			if(T%c[i]==0&&T/c[i]!=1)
			{
				//printf("组合:%d*%d \n",T/c[i],c[i]);
				chu(s);
				for(j=0;j<T/c[i];j++)
				{
					ru(s,c[i]);
				}
				dis(s);
				a_group(c,c[i],i-1,s);
			}	
		}
	}
 }
                         
int main()
{
	int T;
	int c[5]={2,3,4,6,7};//构建候选数组
	sq s;//创建队列
	create(s); 
	printf("输入目标数字:\n");
	scanf("%d",&T);
	a_group(c,T,4,s);
	return 0;
 } 
