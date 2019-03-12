/*
	拓扑排序 
	给任务排序，uva10305 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 26+5
int c[maxn];//算法入门经典中以表的形式，减少了时间复杂度 
int G[maxn][maxn];
int length;
void dfs(int i)
{
	int j;
	//if(length==)
	for(j=0;j<maxn;j++)
	{
		if(G[i][j]==1&&c[j]==0)
		{
			c[i]=i+1;
			length++;
			dfs(j);
		}
		else
			return;
	}
}
void print()
{
	for(int i=0;i<length;i++)
		cout<<c[i]<<" ";
	cout<<endl;
}
void print1()
{
	int i,j;
	for(i=0;i<maxn;i++)
	{
		for(j=0;j<maxn;j++)
			cout<<G[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int n,m;
	int cnt;
	int i,j;
	while(cin>>n>>m)
	{
		char x,y;
		memset(c,0,sizeof(c));
		memset(G,0,sizeof(G));
		//print();
		//print1();
		cnt=0;
		while(cin>>x>>y)
		{
			if(cnt==m)
				break;
			G[x-'a'][y-'a']=1;
			cnt++;
		}
		//print1();
		
		for(i=0;i<maxn;i++)
		{
			for(j=0;j<maxn;j++)
			{
				if(G[i][j]==1)
					break;
			}
			if(G[i][j]==1)
				break;
		}
		length=1;
		dfs(i);
		print();
		if(length==n)
			print(); 
		else
			cout<<"存在有向环"<<endl;	
	}
	return 0;
} 
