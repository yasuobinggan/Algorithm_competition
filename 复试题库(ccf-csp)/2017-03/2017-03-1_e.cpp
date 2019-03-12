#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    cin>>n>>k;
    int cnt=0;
    int wei=0;
    int val;

    for(int i=1;i<=n;i++)
    {
        cin>>val;
        wei+=val;
        if(wei>=k)
        {
            cnt++;
            //cout<<i<<endl;
            wei=0;
        }
        else if(wei<k&&i==n)
        {
            //wei+=val;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
