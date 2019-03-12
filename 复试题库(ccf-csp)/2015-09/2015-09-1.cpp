#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int v[maxn];
int cnt=1;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<n;i++)
    {
        if(v[i]==v[i-1])
            continue;
        else
            cnt++;
    }
    cout<<cnt;
    return 0;
}
/*
8
8 8 8 0 12 12 8 0
*/


