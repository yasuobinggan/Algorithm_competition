#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int INF=0x7F7F7F7F;
int val[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    sort(val+1,val+1+n);
    int MIN=INF;
    for(int i=1;i<=n-1;i++)
    {
        if(abs(val[i+1]-val[i])<MIN)
            MIN=abs(val[i+1]-val[i]);
    }
    cout<<MIN;
    return 0;
}
