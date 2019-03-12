#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int record[maxn];
int main()
{
    memset(record,0,sizeof(record));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int p;
        cin>>p;
        ++record[p];
        cout<<record[p]<<" ";
    }
    return 0;
}
/*
5
1 2 1 1 3
*/
