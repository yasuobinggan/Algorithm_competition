#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int INF=0x3f3f3f3f;
int N,M;
int G[maxn][maxn];
bool visited[maxn][maxn];
int main()
{
    cin>>N>>M;
    memset(visited,false,sizeof(visited));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>G[i][j];
        }
    }
    //每行最小
    for(int i=0;i<N;i++)
    {
        int MIN=INF;
        int minj=0;
        int j;
        for(j=0;j<M;j++)
        {
            if(G[i][j]<MIN)
            {
                MIN=G[i][j];
                minj=j;
            }
        }
        //cout<<i<<" "<<minj<<endl;
        visited[i][minj]=true;
    }
    //每列最大
    for(int j=0;j<M;j++)
    {
        int MAX=-INF;
        int maxi=0;
        int i;
        for(i=0;i<N;i++)
        {
            if(G[i][j]>MAX)
            {
                MAX=G[i][j];
                maxi=i;
            }

        }
        if(visited[maxi][j]==true)
        {
            cout<<maxi<<" "<<j<<" "<<G[maxi][j]<<endl;
        }
    }
    return 0;

}
/*
4 3
11 13 121
407 72 88
25 58 1
134 30 62
*/
