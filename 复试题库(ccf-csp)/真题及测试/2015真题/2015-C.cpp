#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
char G[maxn][maxn];
int visited[maxn][maxn];
int n,m,k;
bool judge(int k,int depth)
{
    int curi=1,curj=k;
    while( 1<=curi && curi<=n && 1<=curj && curj<=m )
    {
        if(visited[curi][curj]==false)
            visited[curi][curj]=true;
        else
        {
            cout<<"No"<<endl;
            return false;
        }

        switch(G[curi][curj])
        {
            case 'N':curi--;depth++;break;
            case 'W':curj--;depth++;break;
            case 'S':curi++;depth++;break;
            case 'E':curj++;depth++;break;
        }
    }
    cout<<depth<<endl;
    return true;
}
int main()
{

    while(cin>>n>>m>>k)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>G[i][j];
            }
        }
        memset(visited,false,sizeof(visited));
        judge(k,0);

    }
    return 0;
}
/*
4 6 5
NNNNSN
NNNSWN
NNSWNN
NSWNNN
3 5 2
NSNNNN
NSWNNN
NENNNN
*/
