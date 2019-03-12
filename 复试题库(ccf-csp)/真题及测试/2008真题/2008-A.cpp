#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int val[maxn];
int N;
bool judge()
{
    int stad=val[2]-val[1];
    for(int i=2;i<=N;i++)
    {
        if(val[i]-val[i-1]!=stad)
            return false;
    }
    return true;
}
int main()
{
    while(cin>>N&&N!=0)
    {

        for(int i=1;i<=N;i++)
        {
            cin>>val[i];
        }
        sort(val+1,val+1+N);
        if(judge())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
