//dfs搜解空间
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
typedef struct Node{
    int st;
    int ed;
    //Node(int _st,int _ed):st(_st),ed(_ed){}
}Node;
Node G[maxn][maxn];
bool visited[maxn][maxn];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int n,m,t;
const int INF=(1<<30)-1;
//vector<Node> p;

void dfs(int x,int y,int length,int &minlength)
{
    //剪枝先行
    if(length>minlength)
        return;
    if(x==n && y==m && length<minlength)
    {

        minlength=length;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int curx=x+dir[i][0];
        int cury=y+dir[i][1];
        if(1<=curx && curx<=n && 1<=cury && cury<=m)
        {
            if(G[curx][cury].st!=0||G[curx][cury].ed!=0)
            {
                if(length+1<G[curx][cury].st || length+1>G[curx][cury].ed)
                {
                    //cout<<"当前坐标:"<<curx<<" "<<cury<<endl;
                    dfs(curx,cury,length+1,minlength);
                }
            }
            else
            {
                //cout<<"当前坐标:"<<curx<<" "<<cury<<endl;
                dfs(curx,cury,length+1,minlength);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>t;
    int r,c,a,b;
    memset(G,0,sizeof(G));
    for(int i=1;i<=t;i++)
    {
        cin>>r>>c>>a>>b;
        G[r][c].st=a;
        G[r][c].ed=b;
    }
    memset(visited,false,sizeof(visited));
    int minlength=INF;

    dfs(1,1,0,minlength);
    cout<<minlength;

    return 0;
}
/*
3 3 3
2 1 1 1
1 3 2 10
2 2 2 10
*/
