//分解质因数
#include<bits/stdc++.h>
using namespace std;
vector<int> res;
vector<int> zhires;
int cut_sum(int num)
{
    int sum=0;
    while(num>0)
    {
        sum+=num%10;
        num/=10;
    }
    return sum;
}
//判断是否是质数true为质数
bool judge(int num)
{
    if(num==2)
        return true;
    else
    {
        for(int i=2;i<=num/2;i++)
        {
            if(num%i==0)
                return false;
        }
        return true;
    }
}
//递归分解质因数
void zhi(int num)
{
    if(judge(num))
    {
        zhires.push_back(num);
        return;
    }
    for(int i=num-1;i>=2;i--)
    {
        if(num%i==0&&judge(i))
        {
            zhires.push_back(i);
            zhi(num/i);
            break;
        }
    }
}

int testout()
{
    int sum=0;
    for(int i=0;i<zhires.size();i++)
    {
        sum+=cut_sum(zhires[i]);
        //cout<<zhires[i]<<" ";
    }
    return sum;
}

int main()
{
    int num;
    while(cin>>num&&num!=0)
    {
        int sum1=cut_sum(num);
        zhires.clear();
        zhi(num);
        int sum2=testout();

        if(sum1==sum2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
