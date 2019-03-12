//缩减标记空间
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
char G[maxn][maxn];
bool visited[maxn][maxn];
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int n,m,q;
//输入坐标,输出二维数组中坐标
void change_p(int &x,int &y)
{
    int temp=y;
    y=x;
    x=n-1-temp;
}
void draw_line(int x1,int y1,int x2,int y2)
{
    if(x1==x2)
    {
        for(int i=min(y1,y2);i<=max(y1,y2);i++)
        {
            if(G[x1][i]=='|')
                G[x1][i]='+';
            else
                G[x1][i]='-';
        }
        return;
    }
    else if(y1==y2)
    {
        for(int i=min(x1,x2);i<=max(x1,x2);i++)
        {
            if(G[i][y1]=='-')
                G[i][y1]='+';
            else
                G[i][y1]='|';
        }
    }
}
void fill_G(int x,int y,char C)
{
    //if(G[x][y]!='|'&&G[x][y]!='-'&&G[x][y]!='+'&&visited[x][y]==false)
    //{
    G[x][y]=C;
    visited[x][y]=true;
    //}
    int curx,cury;
    for(int i=0;i<4;i++)
    {
        curx=x+dir[i][0];
        cury=y+dir[i][1];
        //边界
        if(0<=curx&&curx<=n-1&&0<=cury&&cury<=m-1)
        {
            if(G[curx][cury]!='|'&&G[curx][cury]!='-'&&G[curx][cury]!='+'&&visited[curx][cury]==false)
            {
                fill_G(curx,cury,C);
            }
        }

    }
}
int main()
{
    cin>>m>>n>>q;
    memset(G,'.',sizeof(G));
    memset(visited,false,sizeof(visited));
    int op;
    //画图
    for(int i=0;i<q;i++)
    {
        scanf("%d",&op);
        if(op==0)
        {
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            change_p(x1,y1);change_p(x2,y2);

            draw_line(x1,y1,x2,y2);
        }
        else if(op==1)
        {
            int x,y;
            char C;
            scanf("%d %d %c",&x,&y,&C);
            change_p(x,y);

            fill_G(x,y,C);
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    visited[i][j]=false;
            }
            //memset(visited,false,sizeof(visited));
        }
    }
    //输出结果
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c",G[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
4 2 3
1 0 0 B
0 1 0 2 0
1 0 0 A
//
16 13 9
0 3 1 12 1
0 12 1 12 3
0 12 3 6 3
0 6 3 6 9
0 6 9 12 9
0 12 9 12 11
0 12 11 3 11
0 3 11 3 1
1 4 2 C
*/
