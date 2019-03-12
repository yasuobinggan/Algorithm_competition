//递归一定一定注意递归边界 
#include<bits/stdc++.h>
using namespace std;
#define maxl 505
#define INF (1<<30)-1
typedef struct node{
	int len;
	int cost;
}node;
int N,M,S,D;
node Map[maxl][maxl];
bool vis[maxl];
int d[maxl];
int mincost[maxl];
int pre[maxl];
int len;
void initialize()
{
	for(int i=0;i<maxl;i++)
	{
		for(int j=0;j<maxl;j++)
		{
			Map[i][j].cost=INF;
			Map[i][j].len=INF;
		}
	}
}
void initialize1()
{
	for(int i=0;i<maxl;i++)
	{
		pre[i]=i;
	}
}
void dijkstra(int s)
{
	d[s]=0;
	mincost[s]=0;

	for(int i=0;i<N;i++)
	{
        int u=-1;
        int min=INF;
        for(int j=0;j<N;j++)
        {
            if(vis[j]==false&&d[j]<min)
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
            if(vis[v]==false&&Map[u][v].len!=INF)
            {
                if(d[u]+Map[u][v].len<d[v])
                {
                    d[v]=d[u]+Map[u][v].len;
                    mincost[v]=mincost[u]+Map[u][v].cost;
                    pre[v]=u;
                }
                else if(d[u]+Map[u][v].len==d[v])
                {
                    if(mincost[u]+Map[u][v].cost<mincost[v])
                    {
                        //d[v]=d[u]+Map[u][v];
                        mincost[v]=mincost[u]+Map[u][v].cost;
                        pre[v]=u;
                    }
                }
            }
        }
	}
}
int getlength(int d,int s)
{
	int q=d;
	int length=1;
	while(q!=s)
	{
		q=pre[q];
		length++;
	}
	//length++;
	return length;
}
void dfs(int v,int length)
{
	if(v==S)
	{
		len=length;
		cout<<S<<" ";
		return;
	}
	dfs(pre[v],length+1);
	cout<<v<<" ";
}
int main()
{
	cin>>N>>M>>S>>D;
	//
	initialize();
	for(int i=0;i<M;i++)
	{
		int u,v,len,cost;
		cin>>u>>v>>len>>cost;
		Map[u][v].len=len;
		Map[u][v].cost=cost;
		Map[v][u].len=len;
		Map[v][u].cost=cost;
	}

	fill(d,d+maxl,INF);
	fill(vis,vis+maxl,0);
	fill(mincost,mincost+maxl,INF);
	initialize1();
	dijkstra(S);
    
	dfs(D,1);
	//cout<<D;
	cout<<len<<" "<<mincost[D]; 
	//cout<<getlength(D,S)<<" "<<mincost[D];
	return 0;
}
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/
