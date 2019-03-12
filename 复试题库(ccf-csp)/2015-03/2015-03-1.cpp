#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int G[maxn][maxn];
int n,m;
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
    for(int j=m-1;j>=0;j--)
    {
        for(int i=0;i<n;i++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
