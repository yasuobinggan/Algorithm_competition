#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int v[maxn];
int main()
{
    int n;
    cin>>n;
    int maxabs=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(abs(v[i]-v[i-1])>maxabs)
            maxabs=abs(v[i]-v[i-1]);
    }
    cout<<maxabs;
    return 0;
}
/*
6
2 5 5 7 3 5
*/
