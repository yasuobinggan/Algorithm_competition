/*
	铁轨uva514
		一.模仿出栈行为
		二.模仿进栈行为	 
*/
#include<iostream>
#include<algorithm>
using namespace std;
#define m_l 5
int a[5],tar[5],t_n=5;
void push_top(int value,int t_n)
{
	int i;
	for(i=t_n-1;i>=0;i--)
		tar[i+1]=tar[i];
	tar[0]=value;
	++t_n;
}
void clear()
{
	int i;
	for(i=0;i<5;i++)
		tar[i]=0;
	t_n=0; 
}
bool judge_v(int value,int t_n)//对值判断是否插入 
{
	int i;
	for(i=0;i<t_n;i++)
	{
		if(value==tar[i])
		{
			return 0;
		}
	}
	return 1; 
}
bool judge_s(int value,int i,int a[],int t_n,int &flag)//对列判断是否按照栈的规则 
{
	int j;

	for(j=0;j<t_n;j++)
	{
		if(a[i]==tar[j])
		{
			i++;
		}
		else
			break;
	}
	if(j==t_n)
	{
		flag=i-1;
		clear();
		return 1;
	}
	else
		return 0;
}
int main()
{
	int i,j,flag;
	for(i=0;i<5;i++)
		cin>>a[i];
	for(i=0;i<5;i++)
	{
		if(a[i]==tar[0])
		{
			flag=0;
			if(judge_s(a[i],i,a,t_n,flag))
			{
				i=flag;
				//continue;
			}	
			else
				break;
		}
		else
		{
			for(j=a[i]-1;j>=1;j--)
			{
				if(judge_v(j,t_n))
				{
					push_top(j,t_n); 
				}
			}
		} 
	}
	if(i==5)
		cout<<"YES\n";
	else
		cout<<"NO\n";	
	return 0;
} 

