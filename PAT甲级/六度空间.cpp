//bfs,记录层数
//对记录层数的bfs进行规范化 *
//首次尝试邻接表 
#include<bits/stdc++.h>
using namespace std;
const int maxl=1e4+5;
const int INF=(1<<30)-1;
typedef struct node{
	int data;
	int layer;
}node;
//int G[maxl][maxl];
vector<int> G[maxl];
bool vis[maxl];
double sca[maxl];
int N,M;
double bfs(int root)
{
	double ans=0;
	queue<node> q;
	node rn;
	rn.data=root;
	rn.layer=0;
	q.push(rn);
	while(!q.empty())
	{
		node cn=q.front();
		if(cn.layer<=6)
		{
			ans++;
		}
		else
			break;
		q.pop();
//		for(int i=1;i<=N;i++)
		for(int i=0;i<G[cn.data].size();i++)
		{
			if(vis[G[cn.data][i]]==false)
			{
				vis[G[cn.data][i]]=true;
				//ans++;
				node nn;
				nn.data=G[cn.data][i];
				nn.layer=cn.layer+1;
				q.push(nn);
			}
		}
	 }
	 return ans; 
 } 
int main()
{
	//cin>>N>>M; 
	scanf("%d%d",&N,&M);
	//fill(G[0],G[0]+maxl*maxl,INF);
	for(int i=0;i<M;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		//G[u][v]=G[v][u]=1;
	}
	for(int i=1;i<=N;i++)
	{
		fill(vis,vis+maxl,0);
		vis[i]=1;
		double res=bfs(i);
		//printf("%f\n",res);
		sca[i]=res/N;
	}
	for(int i=1;i<=N;i++)
	{
		printf("%d: %.2f%%\n",i,100*sca[i]);
	}
	return 0;
 }
 /*
 10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
 */ 
