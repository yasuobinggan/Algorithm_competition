//堆优化
#include<bits/stdc++.h>
#define inf (1<<30)-1
#define maxn 10005
using namespace std;
class Node{
    public:
        int v;
        int cost;//源点到此的最短路径
        Node(int vv=0,int c=0)
        {
            v=vv;
            cost=c;
        }
        //优先级队列将按距离从小到大排序
        friend bool operator<(Node n1,Node n2)
        {
            return n1.cost>n2.cost;
        }
};
class Edge{
    public:
        int v,cost;
        Edge(int vv=0,int c=0)
        {
            v=vv;
            cost=c;
        }
};
int n,m;
vector<Edge> G[maxn];//无向图
bool marked[maxn];
int disto[maxn];

//思维核心
int costo[maxn];//接通改点需要增加边的权重
//堆优化
void dijkstra(int s)
{
    //  堆优化的dijkstra
//	1. 将与源点相连的点加入堆，并调整堆。
//	2. 选出堆顶元素u（即代价最小的元素），从堆中删除，并对堆进行调整。
//	3. 处理与u相邻的，未被访问过的，满足三角不等式的顶点
//	1):若该点在堆里，更新距离，并调整该元素在堆中的位置。
//	2):若该点不在堆里，加入堆，更新堆。
//	4. 若取到的u为终点，结束算法；否则重复步骤2、3
    fill(disto,disto+maxn,inf);
    fill(costo,costo+maxn,inf);
    memset(marked,false,sizeof(marked));
    costo[s]=0;
    disto[s]=0;
    priority_queue<Node> pq;
    pq.push(Node(s,0));
    marked[0]=true;

    Node tmp;
    while(!pq.empty())
    {
        tmp=pq.top();
        pq.pop();
        int v=tmp.v;
        if(marked[v])
            continue;
        marked[v]=true;
        int len=G[v].size();
        for(int i=0;i<len;i++)
        {
            //v--->vv
            int vv=G[v][i].v;
            if(marked[vv])
                continue;
            int cost=G[v][i].cost;
            //分支判断s
            if(disto[v]+cost<disto[vv])
            {
                disto[vv]=disto[v]+cost;
                costo[vv]=cost;
                //
                pq.push(Node(vv,disto[vv]));
            }
            //解题关键
            else if(disto[v]+cost==disto[vv])
            {
                costo[vv]=min(costo[vv],cost);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        G[a].push_back(Edge(b,c));
        G[b].push_back(Edge(a,c));
    }

    //初始化在dijkstra中进行
    dijkstra(1);

    //统计边权重
    int res=0;
    for(int i=2;i<=n;i++)
    {
        //cout<<costo[i]<<endl;
        res+=costo[i];
    }
    cout<<res;
    return 0;
}
/*
4 5
1 2 4
1 3 5
2 3 2
2 4 3
3 4 2
*/
