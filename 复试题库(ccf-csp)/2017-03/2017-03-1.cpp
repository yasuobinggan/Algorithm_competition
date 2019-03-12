#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int val[maxn];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    int cnt=0;
    int wei=0;
    for(int i=1;i<=n;i++)
    {
        wei+=val[i];
        if(wei<k&&i==n-1)
        {
            cnt++;
            break;
        }
        if(wei>=k)
        {
            cnt++;
            wei=0;
        }
    }
    cout<<cnt;
    return 0;
}
