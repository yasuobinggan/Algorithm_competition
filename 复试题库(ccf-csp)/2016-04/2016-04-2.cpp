//begin()是迭代器
#include<bits/stdc++.h>
using namespace std;
const int maxn=17;
int G[maxn][maxn],g[maxn][maxn],p;
struct Node{
    int x;
    int y;
    Node(int _x,int _y):x(_x),y(_y){}
    Node(){}
};
vector<Node> point;
//初始化下落方格向量
void init()
{
    for(int i=4;i>=1;i--)
    {
        for(int j=1;j<=4;j++)
        {
            if(g[i][j]==1)
            {
                int curj=j+p-1;
                point.push_back(Node(i,curj));
            }
        }
    }

}
//判断是否可以下落
bool judge()
{
    int low=point.front().x;
    //it是一个指针
    for(vector<Node>::iterator it=point.begin();it!=point.end();it++)
    {
        //是最低层且下一层已被占用||下一层为边界
        if((it->x==low&&G[low+1][it->y]==1)||it->x==15)
        {
            return false;
        }
        if(it->x!=low)
            break;
    }
    return true;
}
void fall()
{
    init();
    while(judge())
    {
        for(vector<Node>::iterator it=point.begin();it!=point.end();it++)
        {
            it->x++;
            //cout<<"下落"<<it->x<<" "<<it->y<<endl;
        }
    }
    //最终位置画图
    //更改向量中的值
    for(vector<Node>::iterator it=point.begin();it!=point.end();it++)
    {
        G[it->x][it->y]=1;
    }
}
void out()
{
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //输入
    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=10;j++)
        {
            cin>>G[i][j];
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            cin>>g[i][j];
        }
    }
    cin>>p;

    //处理
    fall();

    //输出
    out();
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
1 1 1 0 0 0 1 1 1 1
0 0 0 0 1 0 0 0 0 0
0 0 0 0
0 1 1 1
0 0 0 1
0 0 0 0
3
*/
