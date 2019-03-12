#include<bits/stdc++.h>
using namespace std;
int N;
int F(int num)
{
    if(num==0)
        return 7;
    if(num==1)
        return 11;
    return F(num-1)+F(num-2);
}
int main()
{
    cin>>N;
    int value;
    for(int i=1;i<=N;i++)
    {
        cin>>value;
        int ans=F(value);
        if(ans%3==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
