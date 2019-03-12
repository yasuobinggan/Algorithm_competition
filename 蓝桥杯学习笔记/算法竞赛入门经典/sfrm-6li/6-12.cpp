/*
	dfs图 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 100+5
typedef struct{
	int x;
	int y;
}point;
point target[8];
int cnt;
void tar(int idx[maxn][maxn],int i,int j,int &length)
{
	int q,w;
	int k=0;
	for(q=-1;q<=1;q++)
	{
		for(w=-1;w<=1;w++)
		{
			if(q!=0||w!=0)
			{
				target[k].x=i+q;
				target[k].y=j+w;
				k++;
			}
		}
	}
	length=k;
}
void dfs(int idx[maxn][maxn],int m,int n,int i,int j)
{
	int k,length;
	if(i<0||i>=m||j<0||j>=n)//条件可以加入构建数组中，以简化代码为主 
		return;
	if(idx[i][j]==0)
		return;
	idx[i][j]=0;
	memset(target,0,sizeof(target));
	tar(idx,i,j,length);
	for(k=0;k<length;k++)//参考入门经典二维数组等价于一维数组，可以简化代码 
	{
		dfs(idx,m,n,target[k].x,target[k].y);	
	}
}
int main()
{
	char map[maxn][maxn];
	int idx[maxn][maxn];
	int m,n;
	int i,j;
	while(cin>>m>>n)
	{
		memset(idx,0,sizeof(idx));
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='@')
					idx[i][j]=1;
				cout<<idx[i][j]<<"\t";
			}
			cout<<"\n";
		}	
		cnt=0;
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(idx[i][j]==1)
				{
					dfs(idx,m,n,i,j);
		
					++cnt;
				}
				
			}
		}
		
		cout<<"连通块"<<cnt<<endl;
	}
	return 0;
} 
