#include<bits/stdc++.h>
using namespace std;
int r,y,g;
int n;
int main()
{
    cin>>r>>y>>g;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int k,t;
        cin>>k>>t;
        int curflag;
        switch(k)
        {
            case 0:ans+=t;break;
            case 1:
                curflag=(ans+r-t)%(r+g+y);
                if(0<=curflag&&curflag<r)
                {
                    ans+=r-curflag;
                }
                else if(r<=curflag&&curflag<r+g)
                {
                    ans+=0;
                }
                else if(r+g<=curflag&&curflag<r+g+y)
                {
                    ans+=(r+g+y-curflag)+r;
                }
            break;
            case 2:
                curflag=(ans+r+g+y-t)%(r+g+y);
                if(0<=curflag&&curflag<r)
                {
                    ans+=r-curflag;
                }
                else if(r<=curflag&&curflag<r+g)
                {
                    ans+=0;
                }
                else if(r+g<=curflag&&curflag<r+g+y)
                {
                    ans+=(r+g+y-curflag)+r;
                }
            break;
            case 3:
                curflag=(ans+r+g-t)%(r+g+y);
                if(0<=curflag&&curflag<r)
                {
                    ans+=r-curflag;
                }
                else if(r<=curflag&&curflag<r+g)
                {
                    ans+=0;
                }
                else if(r+g<=curflag&&curflag<r+g+y)
                {
                    ans+=(r+g+y-curflag)+r;
                }
            break;

        }
    }
    cout<<ans<<endl;
    return 0;
}
