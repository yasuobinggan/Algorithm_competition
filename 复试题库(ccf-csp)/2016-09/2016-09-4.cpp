//dijkstra路径(dfs)
//vertex顶点 edge边
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,m;
struct Node{
    int v;
    int dis;
    Node(int _v,int _dis):v(_v),dis(_dis){}
};
vector<int> G[maxn];
//直接存放直接前驱结点
vector<int> pre[maxn];
vector<int> path[maxn];
bool vis[maxn];

int main()
{
    cin>>n>>m;
    int u,v,dis;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>dis;
        G[u].push_back(Node(v,dis));
    }
    dijkstra();
    return 0;
}
