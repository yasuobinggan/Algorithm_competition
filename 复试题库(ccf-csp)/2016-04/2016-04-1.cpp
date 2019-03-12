#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;;
int val[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int cnt=0;
    for(int i=1;i<n-1;i++)
    {
        if(val[i]>val[i-1]&&val[i]>val[i+1])
            cnt++;
        else if(val[i]<val[i-1]&&val[i]<val[i+1])
            cnt++;
    }
    cout<<cnt;
    return 0;
}
/*
7
5 4 1 2 3 6 4
*/
