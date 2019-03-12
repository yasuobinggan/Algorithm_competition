//bfs dfs:对解空间的搜索
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
//位运算
const int INF=(1<<30)-1;
int n,m,k,r;
typedef struct point{
    int x;
    int y;
}p;
p visited[maxn];
p temp[maxn];
int flag1[maxn],flag2[maxn];
//int counts=0;
int ans=INF;
//判断是否连通
bool judge(p p1,p p2)
{
    if(abs(p1.x-p2.x)*abs(p1.x-p2.x)+abs(p1.y-p2.y)*abs(p1.y-p2.y)<=(r*r))
        return true;
    else
        return false;
}
int get_length(p p1,p p2)
{
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
//bfs
/*
void bfs()
{
    queue<p> q;
    flag[0]=1;
    q.push(visited[0]);
    while(!q.empty())
    {
        p curp=q.front();
        q.pop();

        for(int i=0;i<n;i++)
        {

        }
        for(int i=0;i<m;i++)
        {

        }
    }
}
*/
//dfs
void printout(vector<p> res)
{
    cout<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<"x:"<<res[i].x<<"y:"<<res[i].y<<endl;
    }
}
void dfs(p node,int limit,int counts,vector<p> res)
{

    if(node.x==visited[1].x&&node.y==visited[1].y)
    {
        if(counts<ans)
        {
            ans=counts;
            //printout(res);
        }
        return;
    }
    if(limit>k)
        return;
    for(int i=1;i<n;i++)
    {
        if(judge(node,visited[i])&&flag1[i]==0)
        {
            flag1[i]=1;
            res.push_back(visited[i]);
            dfs(visited[i],limit,counts+1,res);
            res.pop_back();
            flag1[i]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(judge(node,temp[i])&&flag2[i]==0)
        {
            flag2[i]=1;
            res.push_back(temp[i]);
            dfs(temp[i],limit+1,counts+1,res);
            res.pop_back();
            flag2[i]=0;
        }
    }

}
int main()
{
    cin>>n>>m>>k>>r;
    for(int i=0;i<n;i++)
    {
        cin>>visited[i].x>>visited[i].y;
    }
    for(int i=0;i<m;i++)
    {
        cin>>temp[i].x>>temp[i].y;
    }
    fill(flag1,flag1+maxn,0);
    fill(flag2,flag2+maxn,0);

    //bfs();
    flag1[0]=1;
    vector<p> res;
    dfs(visited[0],0,0,res);
    //printout(res);
    cout<<ans-1;
    return 0;
}
/*
5 3 1 3
0 0
5 5
0 3
0 5
3 5
3 3
4 4
3 0
*/
