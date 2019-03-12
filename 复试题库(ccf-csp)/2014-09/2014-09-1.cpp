#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int val[maxn];
int main()
{
    int n;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    sort(val,val+n);
    for(int i=0;i<=n-2;i++)
    {
        if(abs(val[i]-val[i+1])==1)
            ans++;
    }
    cout<<ans;
    return 0;
}
/*
6
10 2 6 3 7 8
*/
