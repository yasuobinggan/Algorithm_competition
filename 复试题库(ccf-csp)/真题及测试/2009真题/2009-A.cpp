#include<bits/stdc++.h>
using namespace std;
bool get_sum_judge(int num)
{
    int sum=0;
    for(int i=num-1;i>=1;i--)
    {
        if(num%i==0)
        {
            sum+=i;
        }
    }
    if(sum==num)
        return true;
    else
        return false;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        for(int i=a;i<=b;i++)
        {
            if(get_sum_judge(i))
                cout<<i<<endl;
        }
    }

    //cout<<endl;
    return 0;
}
