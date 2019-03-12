//一个图,四个数组


//时间戳 强连通分量中一定存在环
//灵活的回溯判断
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
//城市数量,高速公路数量
int n,m;
struct Node{
    int v;
    Node(int _v):v(_v){}
};
vector<Node> G[maxn];
//dfs时间戳,low整个搜索树中其所在最小子树的根
int dfn[maxn],low[maxn];
//前驱结点
//int head[maxn];
//栈,判断栈中是否存在标记
int _stack[maxn];bool visited[maxn];
//dfn下标,_stack:指向栈顶元素
int index=0,top=0;
//记录连通对数量
int ans=0;
void tarjan(int u)
{
    //对当前节点的访问,操作
    dfn[u]=low[u]=++index;
    _stack[++top]=u;
    visited[u]=true;
    //枚举边进行dfs即可
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].v;
        if(dfn[v]==0)//visited数组判断也可
        {
            tarjan(v);
            //回溯********
            //单向边回溯(非环)
            low[u]=min(low[u],low[v]);
        }
        //回溯
        //被访问过,在栈中(栈在维护一个“强连通分量(环)”,约束到同一个根植上)
        else if(visited[v]==true)
        {
            low[u]=min(low[u],dfn[v]);//dfn环的关键节点
        }
    }
    //回溯
    if(dfn[u]==low[u])
    {
        //弹出的点为一个强连通分量
        while(u!=_stack[top])
        {
            //可实现染色缩点
            visited[_stack[top]]=false;
            --top;
        }
        ans++;
    }
    return;
}
int main()
{
    cin>>n>>m;
    int u,v;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        G[u].push_back(Node(v));
    }
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(_stack,0,sizeof(_stack));
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
            tarjan(i);
    }
    cout<<ans;
    return 0;
}
/*
5 5
1 2
2 3
3 4
4 2
3 5
*/
