#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int val[maxn];
int main()
{
    int n;
    cin>>n;
    memset(val,0,sizeof(val));
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    int ans;
    for(int i=1;i<=n;i++)
    {
        //ans=0;

        if(i==1)
        {
            cout<<(val[i]+val[i+1])/2<<" ";
        }
        else if(i==n)
        {
            cout<<(val[i-1]+val[i])/2<<" ";
        }
        else
            cout<<(val[i-1]+val[i]+val[i+1])/3<<" ";
        //cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}
