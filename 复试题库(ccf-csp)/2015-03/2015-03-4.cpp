//区分交换机，电脑：离散/连续
//双向树：父域，孩子域
//邻接图表示树
/*
//清空vector空间
vector.clear();
vector.shrink_to_fit();//收缩到合适空间大小
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,m;
struct Node{
    int num;
    int anc;
    vector<int> child;
    int level;
    bool visited;
};

Node node[maxn];
int res=-1;
bool judgelast(Node curnode)
{
    for(int i=0;i<curnode.child.size();i++)
    {
        if(node[curnode.child[i]].visited==false)
            return false;
    }
    return true;
}

Node bfs(Node st)
{
    queue<Node> q;
    q.push(st);
    while(!q.empty())
    {
        Node curnode=q.front();

        //获取最后一个结点
        if(q.size()==1&&judgelast(curnode))
        {
            res=curnode.level;
            return curnode;
        }
        //cout<<"当前访问:"<<curnode.num<<" "<<curnode.level<<endl;
        for(int i=0;i<curnode.child.size();i++)
        {
            if(node[curnode.child[i]].visited==false)
            {
                node[curnode.child[i]].visited=true;
                node[curnode.child[i]].level=curnode.level+1;
                q.push(node[curnode.child[i]]);
            }
        }
        q.pop();
    }

}
int main()
{
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        node[i].num=i;
        cin>>node[i].anc;

        node[node[i].anc].child.push_back(i);
        node[i].child.push_back(node[i].anc);
        node[i].visited=false;
    }
    //电脑归于交换机(同等对待)
    //电脑上面一定连的是交换机
    for(int i=n+1;i<=n+m;i++)
    {
        node[i].num=i;
        cin>>node[i].anc;

        node[node[i].anc].child.push_back(i);
        node[i].child.push_back(node[i].anc);
        node[i].visited=false;
    }
    //初始化第一个结点
    node[1].num=1;
    node[1].level=0;
    node[1].anc=-1;
    node[1].visited=true;

    ///第一次bfs
    Node ans=bfs(node[1]);

    //cout<<"目标节点:"<<ans.num<<endl;
    for(int i=1;i<=n+m;i++)
    {
        node[i].level=0;
        node[i].visited=false;
    }
    ///第二次bfs
    ans.level=0;
    bfs(ans);
    cout<<res;

    return 0;
}
//两组测试数据
/*
4 2
1 1 3
2 1

4 4
1 2 2
3 4 4 4
*/

