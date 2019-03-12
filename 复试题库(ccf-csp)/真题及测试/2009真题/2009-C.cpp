#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n;
map<int,int> tab;
//初始化素数表
bool pri(int num)
{
    int sqr=(int)sqrt(num*1.0);
    for(int i=sqr;i>=2;i--)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

void init()
{
    for(int i=2;i<maxn;i++)
    {
        if(pri(i))
            tab[i]=1;
    }
//    for(map<int,int>::iterator it=tab.begin();it!=tab.end();it++)
//    {
//        cout<<"键:"<<it->first<<"值:"<<it->second<<endl;
//    }
}
void pro(string input)
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
    //cout<<"获取数字内容:"<<num<<endl;
    if(num==0||num==2)
    {
        cout<<num<<endl;
        return;
    }

    for(int i=num/2;i>=2;i--)
    {
        if(tab[i]==1&&num%i==0)
        {
            cout<<i<<endl;
            return;
        }
    }
}
int main()
{
    init();
    while(cin>>n)
    {
        string input;
        for(int i=1;i<=n;i++)
        {
            cin>>input;//每次都获取新输入
            pro(input);
        }
    }

    return 0;
}
