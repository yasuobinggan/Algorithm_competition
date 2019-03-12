//Ì°ÐÄ
#include<bits/stdc++.h>
using namespace std;
int N;
int main()
{
    cin>>N;
    int cnt=0;
    while(N>=30)
    {
        if(N>=50)
        {
            N-=50;
            cnt+=7;
        }
        else if(N>=30)
        {
            N-=30;
            cnt+=4;
        }
    }
    cnt+=N/10;
    cout<<cnt;
    return 0;
}
