//注意无向图建立邻接矩阵边的补全
//oj

//欧拉路:通过图中所有边的简单路
//欧拉回路:闭合的欧拉路
//欧拉图:包含欧拉回路的图

//判断是否是连通图,欧拉图,输出路径
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int n,m;
//并查集
int father[maxn];
//对边进行标记
struct Node{
    int v;
    Node(int _v):v(_v){}
};
//出度统计
int out[maxn];
vector<Node> G[maxn];
bool visited[maxn][maxn];

//将图->多分支二层树
int find_father(int x)
{
    if(father[x]==x)
        return x;
    else
    {
        int f=find_father(father[x]);
        //压缩
        father[x]=f;
        return f;
    }
}
bool cmp(Node a,Node b)
{
    return a.v<b.v;
}
//输出欧拉路径
void dfs(int u)
{
    cout<<u<<" ";
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].v;
        if(visited[u][v]==false)
        {
            visited[u][v]=true;
            visited[v][u]=true;
            dfs(v);
        }
    }
}
int main()
{
    cin>>n>>m;
    //memset(father,0,sizeof(father));
    int u,v;
    for(int i=1;i<=n;i++)
        father[i]=i;
    memset(out,0,sizeof(out));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;i++)
    {
        //建立邻接矩阵
        cin>>u>>v;
        G[u].push_back(Node(v));
        G[v].push_back(Node(u));
        out[u]++;
        out[v]++;
        //并查集
        father[u]=v;
        int f=find_father(u);
        father[u]=f;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<father[i]<<" ";
        if(father[i]==i)
            cnt++;
    }

    if(cnt==1)
    {
        int cntodd=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<i<<" "<<out[i]<<endl;
            if(out[i]%2==0)
                continue;
            else
                cntodd++;
        }
        if((cntodd==2&&out[1]%2==1)||cntodd==0)
        {
            //对分支进行排序便于输出
            for(int i=1;i<=n;i++)
            {
                sort(G[i].begin(),G[i].end(),cmp);
            }
            dfs(1);
        }
        else
        {
            cout<<-1;
            return 0;
        }


    }
    else
    {
        cout<<cnt<<endl;
        cout<<-1;
        return 0;
    }

    return 0;
}
/*
4 5
1 2
1 3
1 4
2 4
3 4

//

4 6
1 2
1 3
1 4
2 4
3 4
2 3
*/
