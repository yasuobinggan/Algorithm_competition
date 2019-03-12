//无向图 
#include<bits/stdc++.h>
using namespace std;
const int INF=(1<<30)-1;
const int maxl=500;

int Map[maxl][maxl];
int C[maxl];
int N,M,C1,C2;
int d[maxl];//最短路径长度
bool vis[maxl];//节点访问数组 
int maxhand[maxl];//最大节点权值 
int minlen[maxl];//最短路径数量 

void dijkstra(int s)
{
	d[s]=0;
	maxhand[s]=C[s];
	minlen[s]=1;
	for(int i=0;i<N;i++)
	{
		int u=-1;
		int min=INF; 
		for(int j=0;j<N;j++)
		{
			if(d[j]<min&&vis[j]==false)
			{
				u=j;
				min=d[j];
			}
		}
		vis[u]=true;
		if(u==-1)
			return;
		for(int v=0;v<N;v++)
		{
			if(vis[v]==false&&Map[u][v]<INF)
			{
				if(d[u]+Map[u][v]<d[v])
				{
					d[v]=d[u]+Map[u][v];
					//if(maxhand[u]+C[v]>maxhand[v])
					//{
					maxhand[v]=maxhand[u]+C[v];
					//}
					minlen[v]=minlen[u]; 
				}
					
				else if(d[u]+Map[u][v]==d[v])
				{
					minlen[v]+=minlen[u];
					if(maxhand[u]+C[v]>maxhand[v])
					{
						maxhand[v]=maxhand[u]+C[v];
					}
				}
			}
		}
	}
}

int main()
{
	cin>>N>>M>>C1>>C2;
	for(int i=0;i<N;i++)
		cin>>C[i];
	fill(Map[0],Map[0]+maxl*maxl,INF);
	for(int i=0;i<M;i++)
	{
		int u,v,l;
		cin>>u>>v>>l;
		Map[u][v]=l;
		Map[v][u]=l;
	 }
	 
	fill(d,d+maxl,INF);  
	fill(minlen,minlen+maxl,0);
	fill(maxhand,maxhand+maxl,-1);
	dijkstra(C1);
	
	//for(int i=0;i<N;i++)
	//	cout<<d[i]<<" ";
	//cout<<endl;
	cout<<minlen[C2]<<" "<<maxhand[C2]; 
	  
	return 0;
 }
 /*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
 */ 
