#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int G[maxn][maxn];
int dir[4][2]={{0,1},{1,0},{1,-1},{-1,1}};

bool Isright(int x,int y,int n)
{
    if(1<=x&&x<=n&&1<=y&&y<=n)
    {
        return true;
    }
    return false;
}

int main()
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>G[i][j];
    x=1;y=1;
    cout<<G[x][y]<<" ";
    if(n%2==0)
    {
        //左上角
        while(true)
        {
            x+=dir[0][0];
            y+=dir[0][1];
            cout<<G[x][y]<<" ";
            while(Isright(x+dir[2][0],y+dir[2][1],n))
            {
                x+=dir[2][0];
                y+=dir[2][1];
                cout<<G[x][y]<<" ";
            }
            if(x==n&&y==1)
                break;
            x+=dir[1][0];
            y+=dir[1][1];
            cout<<G[x][y]<<" ";
            while(Isright(x+dir[3][0],y+dir[3][1],n))
            {
                x+=dir[3][0];
                y+=dir[3][1];
                cout<<G[x][y]<<" ";
            }
            //cout<<"跳出标志"<<x<<" "<<y<<endl;
        }
        x=n;y=1;
        //右下角
        while(true)
        {
            x+=dir[0][0];
            y+=dir[0][1];
            cout<<G[x][y]<<" ";
            if(x==n&&y==n)
                break;
            while(Isright(x+dir[3][0],y+dir[3][1],n))
            {
                x+=dir[3][0];
                y+=dir[3][1];
                cout<<G[x][y]<<" ";
            }
            x+=dir[1][0];
            y+=dir[1][1];
            cout<<G[x][y]<<" ";
            while(Isright(x+dir[2][0],y+dir[2][1],n))
            {
                x+=dir[2][0];
                y+=dir[2][1];
                cout<<G[x][y]<<" ";
            }

        }
    }
    else
    {
        //左上角
        while(true)
        {
            x+=dir[0][0];
            y+=dir[0][1];
            cout<<G[x][y]<<" ";
            while(Isright(x+dir[2][0],y+dir[2][1],n))
            {
                x+=dir[2][0];
                y+=dir[2][1];
                cout<<G[x][y]<<" ";
            }
            if(x==1&&y==n)
                break;
            x+=dir[1][0];
            y+=dir[1][1];
            cout<<G[x][y]<<" ";
            while(Isright(x+dir[3][0],y+dir[3][1],n))
            {
                x+=dir[3][0];
                y+=dir[3][1];
                cout<<G[x][y]<<" ";
            }
            if(x==1&&y==n)
                break;
            //cout<<"跳出标志"<<x<<" "<<y<<endl;
        }
        //x=1;y=n;
        //右下角
        while(true)
        {
            x+=dir[1][0];
            y+=dir[1][1];
            cout<<G[x][y]<<" ";
            while(Isright(x+dir[2][0],y+dir[2][1],n))
            {
                x+=dir[2][0];
                y+=dir[2][1];
                cout<<G[x][y]<<" ";
            }

            x+=dir[0][0];
            y+=dir[0][1];
            cout<<G[x][y]<<" ";
            if(x==n&&y==n)
                break;
            while(Isright(x+dir[3][0],y+dir[3][1],n))
            {
                x+=dir[3][0];
                y+=dir[3][1];
                cout<<G[x][y]<<" ";
            }
        }
    }
    return 0;
}
