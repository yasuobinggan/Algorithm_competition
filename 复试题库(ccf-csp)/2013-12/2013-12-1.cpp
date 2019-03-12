#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int val[maxn];
int main()
{
    int n;
    int value;
    cin>>n;
    fill(val,val+maxn,0);
    while(n--)
    {
        cin>>value;
        val[value]++;
    }
    int maxi=0,maxval=-1;
    for(int i=0;i<maxn;i++)
    {
        if(val[i]>maxval)
        {
            maxval=val[i];
            maxi=i;
        }
    }
    cout<<maxi;
    return 0;
}
