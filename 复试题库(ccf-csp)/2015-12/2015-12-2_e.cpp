#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int G[maxn][maxn];
bool visited[maxn][maxn];
int n,m;
int main()
{
    memset(visited,false,sizeof(visited));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>G[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-2;j++)
        {
            if(G[i][j]==G[i][j+1]&&G[i][j]==G[i][j+2])
            {
                visited[i][j]=visited[i][j+1]=visited[i][j+2]=true;
            }
        }
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(G[i][j]==G[i+1][j]&&G[i][j]==G[i+2][j])
            {
                visited[i][j]=visited[i+1][j]=visited[i+2][j]=true;
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(visited[i][j]==true)
            {
                cout<<0<<" ";
            }
            else
                cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
