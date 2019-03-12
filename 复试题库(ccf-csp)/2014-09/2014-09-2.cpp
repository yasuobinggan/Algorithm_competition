#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int sum=0;
bool flag[maxn][maxn];
int main()
{
    int n,x1,y1,x2,y2;
    cin>>n;
    memset(flag,false,sizeof(flag));
    for(int w=0;w<n;w++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<x2;i++)
        {
            for(int j=y1;j<y2;j++)
            {
                if(flag[i][j]==false)
                {
                    //cout<<i<<" "<<j<<endl;
                    flag[i][j]=true;
                    sum++;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
/*
2
1 1 4 4
2 3 6 5
*/
