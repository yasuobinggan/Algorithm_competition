//Ïò×óÑ­»·
#include<bits/stdc++.h>
using namespace std;
int r,y,g;
int n;
int k,t;
int main()
{
    cin>>r>>y>>g;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int k,t;
        cin>>k>>t;
        switch(k)
        {
            case 0:ans+=t;break;
            case 1:ans+=t;break;
            case 2:ans+=t;ans+=r;break;
            case 3:break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
