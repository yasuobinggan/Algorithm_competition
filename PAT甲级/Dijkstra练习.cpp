#include<bits/stdc++.h>
using namespace std;
const int maxv=1000;
const int INF=(1<<30)-1;//表示不连通

int n,m,s,G[maxv][maxv];//n为顶点数,m为边数,s为起点
int d[maxv];//起点到各个点的最短距离 
bool vis[maxv];
void Dijkstra(int s)//起点同样需要初始化 
{
	d[s]=0;//到自己的距离为0
	 
	for(int i=0;i<n;i++)//每个点都需要找一下 
	{
		int min=INF;
		int u=-1;//记录最短节点，方便更新 
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j]; 
			}
		}
		vis[u]=true;//记录已经访问
		if(u==-1)//图中存在不连通 
			return;
		for(int k=0;k<n;k++)
		{
			if(vis[k]==false&&G[u][k]<INF&&d[u]+G[u][k]<d[k])
			{
				d[k]=d[u]+G[u][k];	
			}	
		}	
	 } 
 } 
int main()
{
	int u,v,w;//可以用作图输入的常用变量名 
	cin>>n>>m>>s;//顶点个数,边数,起点编号
	
	//初始化图 
	fill(G[0],G[0]+maxv*maxv,INF);
	for(int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u][v]=w;
	 }
	 
	 //Dijkstra 
	fill(d,d+maxv,INF);//距离数组 
	fill(vis,vis+maxv,0);//访问数组 
	//vis[s]=true;
	 Dijkstra(s);
	//
	 for(int i=0;i<n;i++)
	 {
	 	cout<<d[i]<<" ";
	 }
	return 0;
}
/*
6 8 0
0 1 1
0 3 4
0 4 4 
1 3 2
2 5 1
3 2 2
3 4 3
4 5 3 
*/
