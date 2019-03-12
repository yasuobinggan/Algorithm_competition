//#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
vector<int> cut;
void cut_num(int num)
{
    while(num>0)
    {
        cut.push_back(num%10);
        num/=10;
    }
}
int three(int a)
{
    return a*a*a;
}
bool cal_judge(int num)
{
    int value=0;
    for(int i=0;i<cut.size();i++)
    {
        //cout<<"每位数字:"<<three(cut[i])<<endl;
        value+=three(cut[i]);
    }

    if(value==num)
        return true;
    else
        return false;
}
int main()
{
    int st,ed;
    while(cin>>st>>ed)
    {
        int cnt=0;
        for(int num=st;num<=ed;num++)
        {
            cut.clear();
            cut_num(num);
            //cout<<"输出:"<<endl;
            if(cal_judge(num))
            {
                cout<<num<<" ";
                cnt++;
            }
        }
        if(cnt==0)
            cout<<"no";
        cout<<endl;
    }
    return 0;
}
