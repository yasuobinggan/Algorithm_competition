//实现简单模拟
#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n,m;
int G[maxn][maxn];
//bool curvis[maxn][maxn];
bool visited[maxn][maxn];
int dir1[2][2]={0,1,0,-1};
int dir2[2][2]={1,0,-1,0};

void judge(int x,int y)
{
    int cnt1=0,cnt2=0;
    int curx=x,cury=y;
    //横向判断
    while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
    {
        cnt1++;
        curx+=dir1[0][0];cury+=dir1[0][1];
    }
    curx=x;cury=y-1;
    while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
    {
        cnt1++;
        curx+=dir1[1][0];cury+=dir1[1][1];
    }
    if(cnt1>=3)
    {
        curx=x;cury=y;
        while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
        {
            visited[curx][cury]=true;
            curx+=dir1[0][0];cury+=dir1[0][1];
        }
        curx=x;cury=y-1;
        while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
        {
            visited[curx][cury]=true;
            curx+=dir1[1][0];cury+=dir1[1][1];
        }
    }
    //纵向判断
    curx=x;cury=y;
    while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
    {
        cnt2++;
        curx+=dir2[0][0];cury+=dir2[0][1];
    }
    curx=x-1;cury=y;
    while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
    {
        cnt2++;
        curx+=dir2[1][0];cury+=dir2[1][1];
    }
    if(cnt2>=3)
    {
        curx=x;cury=y;
        while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
        {
            visited[curx][cury]=true;
            curx+=dir2[0][0];cury+=dir2[0][1];
        }
        curx=x-1;cury=y;
        while(G[curx][cury]==G[x][y]&&0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
        {
            visited[curx][cury]=true;
            curx+=dir2[1][0];cury+=dir2[1][1];
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>G[i][j];
        }
    }
    //memset(curvis,false,sizeof(curvis));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==0)
            {
                judge(i,j);
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==false)
            {
                cout<<G[i][j]<<" ";
            }
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*
4 5
2 2 3 1 2
3 4 5 1 4
2 3 2 1 3
2 2 2 4 4
//
4 5
2 2 3 1 2
3 1 1 1 1
2 3 2 1 3
2 2 3 3 3
*/
