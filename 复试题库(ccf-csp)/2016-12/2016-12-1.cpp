#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int val[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    sort(val,val+n);
    int mid=n/2;
    int st=mid,ed=mid;
    while(val[st]==val[mid])
        --st;
    while(val[ed]==val[mid])
        ++ed;
    int len1=st+1;
    int len2=n-ed;
    if(len1==len2)
        cout<<val[mid];
    else
        cout<<-1;
    return 0;
}
/*
6
2 6 5 6 3 5
//
4
3 4 6 7
//
5
3 4 6 6 7
*/
