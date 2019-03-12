#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int a[maxn][maxn];
//ÕÒ¹æÂÉ
int main()
{
    int n,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    x=0;y=0;

    for(int i=0;i<n;i++)
    {
        if(i&1)
        {
            for(int j=0;j<i;j++)
                cout<<a[x++][y--]<<" ";
            cout<<a[x++][y]<<" ";
        }
        else
        {
            for(int j=0;j<i;j++)
                cout<<a[x--][y++]<<" ";
            cout<<a[x][y++]<<" ";
        }
    }

    if(n&1)
        y--,x++;
    else
        y++,x--;

    for(int i=n-2;i>0;i--)
    {
        if(i&1)
        {
            for(int j=0;j<i;j++)
                cout<<a[x++][y--]<<" ";
            cout<<a[x][y++]<<" ";
        }
        else
        {
            for(int j=0;j<i;j++)
                cout<<a[x--][y++]<<" ";
            cout<<a[x++][y]<<" ";
        }
    }

    if(n!=1)
        cout<<a[n-1][n-1]<<endl;
    return 0;
}
