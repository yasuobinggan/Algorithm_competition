/*
交换学生uva10763
	输入n,和n种情况 
	1.使用map不是很合理 
*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
#define m_l 500000
map<int,int> cnt;//全局变量 
void judge()
{
	int i,j;
	for(i=0;i<m_l;i++)
	{
		for(j=0;j<m_l;j++)
		{
			if(j!=i)
			{
				if(cnt[i]==j && cnt[j]==i)
				{
					cout<<"YES\n";
					return; 
				}
			}
		}
	}
	cout<<"NO\n";
	return;
}
int main()
{
	int n,n_max,i,j;
	int a,b;
	cin>>n;
	
	while(n-->0)
	{
		cin>>a>>b;
		cnt[a]=b;
	}
	judge(); 
	return 0;
}
