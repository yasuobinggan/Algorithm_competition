//图的最小生成树
//O(v^2)
#include<bits/stdc++.h>
using namespace std;
const int INF=(1<<30)-1;
const int maxn=100005;
int n,m;
struct Node{
    int v,dis;
};
vector<Node> G[maxn];
int d[maxn];
bool visited[maxn];
int ans=0;
//大循环让prim运行
void prim(int st)
{
    //[d,d+n)填充
    fill(d,d+1+n,INF);
    d[1]=0;

    for(int w=1;w<=n;w++)
    {
        int mindis=INF,u=-1;
        for(int i=1;i<=n;i++)
        {
            if(d[i]<mindis && visited[i]==false)
            {
                mindis=d[i];
                u=i;
            }
        }
        if(u==-1)
        {
            return;//cout<<"非连通图"<<endl;
        }

        visited[u]=true;
        ans+=mindis;//ans+=d[u];

        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i].v;
            int dis=G[u][i].dis;
            if(visited[v]==false&&dis<d[v])///区别
            {
                d[v]=dis;///区别
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,dis;
        cin>>u>>v>>dis;
        //无向图
        Node node1;
        node1.v=v;node1.dis=dis;
        G[u].push_back(node1);
        Node node2;
        node2.v=u;node2.dis=dis;
        G[v].push_back(node2);
    }
    memset(visited,false,sizeof(visited));

    prim(1);

    //cout<<"结果:";
    cout<<ans;
    return 0;
}
/*
4 4
1 2 1
2 3 4
2 4 2
3 4 3
*/
