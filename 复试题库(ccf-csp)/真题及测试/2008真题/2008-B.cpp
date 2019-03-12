#include<bits/stdc++.h>
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
    int num;
    while(cin>>num&&num!=0)
    {
        cut.clear();
        cut_num(num);
        //cout<<"输出:"<<endl;
        if(cal_judge(num))
        {
            cout<<"Yes"<<endl;
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
