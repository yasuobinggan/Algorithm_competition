#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll r,y,g,n,k,t;
    ll ans=0;
    scanf("%lld%lld%lld",&r,&y,&g);
    ll sum=r+y+g;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld",&k,&t);
        if(k==0)
        {
            ans+=t;
        }
        else if(k==1)
        {
            ///
            t-=ans;
            t=(t%sum+sum)%sum;
            ///
            if(t>r)
            {
                t-=r;
                if(t<=y)
                {
                    ans+=t+r;
                }
            }
            else
            {
                ans+=t;
            }
        }
        else if(k==2)
        {
            ///
            t+=r;
            t-=ans;
            t=(t%sum+sum)%sum;
            ///
            if(t>r)
            {
                t-=r;
                if(t<=y)
                {
                    ans+=t+r;
                }
            }
            else
            {
                ans+=t;
            }
        }
        else
        {
            ///
            t+=r+y;
            t-=ans;
            t=(t%sum+sum)%sum;
            ///
            if(t>r)
            {
                t-=r;
                if(t<=y)
                {
                    ans+=t+r;
                }
            }
            else
            {
                ans+=t;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
