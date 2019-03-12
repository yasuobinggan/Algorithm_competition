#include<bits/stdc++.h>
using namespace std;
//2进制转十进制
void two_to_ten(int num)
{
    vector<int> cut;
    int ans=0;
    int cnt=0;//2的次幂
    while(num>0)
    {
        cut.push_back(num%10);
        num/=10;
    }
    for(int i=cut.size()-1;i>=0;i--)
    {
        ans*=2;
        ans+=cut[i];
    }

    cout<<ans<<endl;
}
//十进制转2进制
void ten_to_two(int num)
{
    vector<int> cut;
    while(num>0)
    {
        cut.push_back(num%2);
        num/=2;
    }
    for(int i=cut.size()-1;i>=0;i--)
        cout<<cut[i];
    cout<<endl;
}
int main()
{
    int num,m;
    while(cin>>num>>m)
    {
        if(m==2)
        {
            two_to_ten(num);
        }
        else
        {
            ten_to_two(num);
        }
    }
    return 0;
}
