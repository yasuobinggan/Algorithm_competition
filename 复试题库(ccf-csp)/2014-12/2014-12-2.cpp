/*************ERROR***************/
//提前判断
//左上三角与右下区分
#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int dir[4][2]={0,1,1,0,1,-1,-1,1};
int G[maxn][maxn];
int n;
void Zigzag(int x,int y)
{
    int curx,cury;
    while(true)
    {

        curx=x+dir[0][0];
        cury=y+dir[0][1];
        if(cury<=n-1)
        {
            cout<<G[curx][cury]<<" ";
            x=curx;y=cury;
        }
        else
        {
            curx=x;cury=y;
        }
        if(x==n-1&&y==0)
        {
            break;
        }
        while(curx<=n-1&&cury>=0)
        {
            curx=x+dir[2][0];
            cury=y+dir[2][1];
            if(curx<=n-1&&cury>=0)
            {
                cout<<G[curx][cury]<<" ";
                x=curx;y=cury;
            }

        }
        if(x==n-1&&y==0)
        {
            break;
        }
        curx=x+dir[1][0];
        cury=y+dir[1][1];
        if(curx<=n-1)
        {
            cout<<G[curx][cury]<<" ";
            x=curx;y=cury;
        }
        else
        {
            curx=x;cury=y;
        }
        if(x==n-1&&y==0)
        {
            break;
        }
        while(curx>=0&&cury<=n-1)
        {
            curx=x+dir[3][0];
            cury=y+dir[3][1];
            if(curx>=0&&cury<=n-1)
            {
                cout<<G[curx][cury]<<" ";
                x=curx;y=cury;
                //cout<<"zuo biao: "<<x<<" "<<y<<endl;
            }
        }
        if(x==n-1&&y==0)
        {
            break;
        }
    }
    /*
    while(true)
    {
        curx=x+dir[0][0];
        cury=y+dir[0][1];
        if(cury<=n-1)
        {
            cout<<G[curx][cury]<<" ";
            x=curx;y=cury;
        }
        else
        {
            curx=x;cury=y;
        }
        if(x==n-1&&y==n-1)
        {
            break;
        }
        while(curx>=0&&cury<=n-1)
        {
            curx=x+dir[3][0];
            cury=y+dir[3][1];
            if(curx>=0&&cury<=n-1)
            {
                cout<<G[curx][cury]<<" ";
                x=curx;y=cury;
                //cout<<"zuo biao: "<<x<<" "<<y<<endl;
            }
        }

        if(x==n-1&&y==n-1)
        {
            break;
        }
        curx=x+dir[1][0];
        cury=y+dir[1][1];
        if(curx<=n-1)
        {
            cout<<G[curx][cury]<<" ";
            x=curx;y=cury;
        }
        else
        {
            curx=x;cury=y;
        }
        if(x==n-1&&y==n-1)
        {
            break;
        }
        while(curx<=n-1&&cury>=0)
        {
            curx=x+dir[2][0];
            cury=y+dir[2][1];
            if(curx<=n-1&&cury>=0)
            {
                cout<<G[curx][cury]<<" ";
                x=curx;y=cury;
            }

        }
        if(x==n-1&&y==n-1)
        {
            break;
        }
    }
    */
}
int main()
{

    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>G[i][j];
        }
    }
    cout<<G[0][0]<<" ";
    Zigzag(0,0);
    return 0;
}
/*
4
1 5 3 9
3 7 5 6
9 4 6 4
7 3 1 3
*/
