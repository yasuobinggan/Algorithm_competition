#include<stdio.h>
#define m_n 30
/**
	uva815
	Ì°ÐÄ 
*/
void sort(int a[m_n][m_n],int n,int m,int s[])
{
	int i,j,k=0;
	int temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			s[k]=a[i][j];
			k++;
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(s[j]>s[j+1])
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}		
		}
	}	
}
int f(int s[],int n*m,int flood)
{
	int i;
	int count=0,sum=0,area=100;
	for(i=0;i<n*m;i++)
	{
		sum+=s[i]*area;
		if(sum<flood)
	}
}
int main()
{
	int a[m_n][m_n],n,m;
	int i,j;
	int s[m_n*m_n];
	int flood; 
	scanf("%d%d",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	sort(a,n,m,s);
	scanf("%d",&flood);	
	f(s,n*m,flood);
	return 0;
} 