//字符串模拟题
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int p,r,u,q;
string op[maxn];
typedef struct role{
    string r;
    vector<string> privilege;
}role;
role roles[maxn];
typedef struct user{
    string u;
    vector<string> roles;
}user;
user users[maxn];
string sch[maxn];
int main()
{
    //权限
    cin>>p;
    for(int i=0;i<p;i++)
    {
        cin>>op[i];
    }
    //角色
    cin>>r;
    for(int i=0;i<r;i++)
    {
        cin>>roles[i].r;
        int num;
        for(int j=0;j<num;j++)
        {
            string pri;
            cin>>pri;
            roles[i].privilege.push_back(pri);
        }
    }
    //用户
    cin>>u;
    for(int i=0;i<u;i++)
    {
        cin>>users[i].u;
        int num;
        for(int j=0;j<num;j++)
        {
            string _role;
            cin>>_role;
            users[i].roles.push_back(_role);
        }
    }
    cin>>q;
    for(int i=0;i<q;i++)
    {
        cin>>sch[i];
    }
    return 0;
}
