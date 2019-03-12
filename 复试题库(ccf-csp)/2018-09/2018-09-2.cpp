#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int cnt[maxn];
int main()
{
    memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    int ai,bi;
    // ‰»Î
    for(int i=1;i<=n;i++)
    {
        cin>>ai>>bi;
        for(int j=ai;j<bi;j++)
        {
            cnt[j]=1;
        }
    }
    int ci,di;
    // ‰»Î
    for(int i=1;i<=n;i++)
    {
        cin>>ci>>di;
        for(int j=ci;j<di;j++)
        {
            if(cnt[j]==1)
                cnt[j]=2;
        }
    }
    int ans=0;
    for(int i=1;i<=maxn;i++)
    {
        if(cnt[i]==2)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
