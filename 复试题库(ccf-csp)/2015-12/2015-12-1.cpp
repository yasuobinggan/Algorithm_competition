#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int n;
//int num[maxn];
int ans=0;
void glit(int n)
{
    int i=0;
    while(n>0)
    {
        ans+=(n%10);
        n/=10;
    }
}
int main()
{
    cin>>n;
    glit(n);
    cout<<ans;
    return 0;
}
