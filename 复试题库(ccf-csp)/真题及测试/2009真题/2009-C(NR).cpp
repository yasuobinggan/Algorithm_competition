//快速分解质因子
#include<bits/stdc++.h>
using namespace std;

int f(int num)
{
    //获取最大的质因子
    int Max=-1;
    //快速分解质因子

    for(int i=2;i*i<=num;i++)
    {
        //对可能的最小因子连续分解
        while(num%i==0)
        {
            if(i>Max)
                Max=i;
            num/=i;
        }
    }
    if(num>1)
    {
        if(num>Max)
        {
            Max=num;
        }
    }
    return Max;
}
int main()
{
    int n;
    while(cin>>n)
    {
        int num=0;
        for(int i=0;i<input.size();i++)
        {
            if(0<=input[i]-'0'&&input[i]-'0'<=9)
            {
                num*=10;
                num+=input[i]-'0';
            }
        }
    }
    if(num==0)
        cout<<num<<endl;
    else
        cout<<f(num)<<endl;
    return 0;
}
