/*
	求迷宫中一个点到另一个点的最短距离 
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define maxn 100+5
typedef struct{
	int x;
	int y;
}point;
queue<point> q;
int map[maxn][maxn];
int cnt[maxn][maxn];//距离矩阵
//void bfs(int** map,int** cnt,int n,int m)
void print(int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			//cout<<map[i][j]<<"\t";
		//cout<<"\n";
		map[i][j]=1;
	}
	//cout<<endl;
}
void print1(int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<cnt[i][j]-1<<"\t";
		cout<<"\n";
		//map[i][j]=1;
	}
	cout<<endl;
}
void bfs(int map[maxn][maxn],int cnt[maxn][maxn],int n,int m)
{
	int i,j;
	while(!q.empty())
	{
		point p=q.front();
		
		for(i=-1;i<=1;i++)
		{
			if(i!=0)
			{
				if(p.x+i>=0&&p.x+i<=n&&map[p.x+i][p.y]==1&&cnt[p.x+i][p.y]==0)
				{
					point p1;
					p1.x=p.x+i;p1.y=p.y;
					q.push(p1);
					map[p1.x][p1.y]=0;
					cnt[p1.x][p1.y]=cnt[p.x][p.y]+1;
					//print(n,m);
				}
			}
		}
		for(j=-1;j<=1;j++)
		{
			if(j!=0)
			{
				if(p.y+j>=0&&p.y+j<=m&&map[p.x][p.y+j]==1&&cnt[p.x][p.y+j]==0)
				{
					point p1;
					p1.x=p.x;p1.y=p.y+j;
					q.push(p1);
					map[p1.x][p1.y]=0;
					cnt[p1.x][p1.y]=cnt[p.x][p.y]+1;
					//print(n,m);
				}
			}
		}
		q.pop();
	}
} 
int main()
{
	int n,m,i,j;
	int rx,ry;
	while(cin>>n>>m)
	{
		//memset(map,1,sizeof(map));
		print(n,m);
		while(!q.empty())
		{
			q.pop();
		}
		while(cin>>i>>j)//输入障碍坐标
		{
			if(i==-1)
				break;
			map[i][j]=0;
		} 
		//print(n,m);	
		memset(cnt,0,sizeof(cnt));
		cin>>rx>>ry;
		point p;
		p.x=rx;p.y=ry;
		q.push(p);
		cnt[rx][ry]=1;
		bfs(map,cnt,n,m);
		print1(n,m);
	}
	return 0;
} 
