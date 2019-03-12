#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
int val[maxn];
int pos[maxn];
int len=1;
void testout()
{
    for(int i=1;i<len;i++)
        cout<<val[i]<<" ";
    cout<<endl;
}
int main()
{
    int ans;
    while(true)
    {
        cin>>pos[len];
        if(pos[len]==0)
            break;
        len++;
    }

    for(int i=1;i<len;i++)
    {
        if(pos[i]==1)
        {
            val[i]=1;
            ans+=1;
        }
        else if(pos[i]==2)
        {
            if(i==1)
            {
                val[i]=2;
                ans+=2;
            }
            else if(pos[i-1]==1)
            {
                val[i]=2;
                ans+=2;
            }
            else if(pos[i-1]==2)
            {
                val[i]=val[i-1]+2;
                ans+=val[i];
            }
        }
    }
    //testout();
    cout<<ans;
    return 0;
}
