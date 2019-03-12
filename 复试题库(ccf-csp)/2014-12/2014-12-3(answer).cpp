#include<bits/stdc++.h>
using namespace std;
struct data{
    string a;
    float b;//出价
    long long c;//股数
    int d;//是否失效
};
struct money{
    float a;
    long long b,s;
};
vector<data> notes;
vector<money> mon;
data dtemp;
money mtemp;

bool cmp(data a,data b)
{
    if(a.d==b.d&&a.d==1)
    {
        return a.b<b.b;
    }
    return a.d>b.d;
}

void M_find(float a,string b,long long c)
{
    int i;
    for(i=0;i<mon.size();i++)
    {
        if(mon[i].a==a)
        {
            if(b=="buy")
        }
    }
}
int main()
{
    //cout<<(1<<30)-1;
    while(cin>>dtemp.a)
    {
        if(dtemp.a=="buy"||dtemp.a=="sell")
        {
            cin>>dtemp.b>>dtemp.c;
            dtemp.d=1;
        }
        else if(dtemp.a=="cancel")
        {
            cin>>dtemp.b;
            //
            notes[dtemp.b-1].d=0;
            dtemp.d=0;
        }
        else
            break;
        notes.push_back(dtemp);
    }

    sort(notes.begin(),notes.end(),cmp);
    for(int i=notes.begin(),notes.end(),com)
    {
        if(notes[i].d==1)
        {
            find(notes[i].b,notes[i].a,notes[i].c);
        }
    }
    return 0;
}
