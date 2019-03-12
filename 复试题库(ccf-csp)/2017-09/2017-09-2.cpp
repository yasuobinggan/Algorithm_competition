//时间模拟
//结构体的构造函数
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
int val[maxn];
bool visited[maxn];
int N,K;
//灵活设置结构体
struct teacher{
    int key;
    int st;
    int ed;
    /*
    teacher(int _key,int _st,int _len)
    {
        key=_key;
        st=_st;
        len=_len;
    }
    */
};
teacher t[maxn];
void testout()
{
    for(int i=1;i<=N;i++)
        cout<<val[i]<<" ";
}
//找到第一个空位
int find_empty()
{
    for(int i=1;i<=N;i++)
    {
        if(visited[i]==false)
            return i;
    }
}
int main()
{
    memset(val,0,sizeof(val));
    //false钥匙槽为空
    memset(visited,true,sizeof(visited));
    for(int i=0;i<=N;i++)
        cout<<visited[i];
    cin>>N>>K;
    for(int i=1;i<=N;i++)
        val[i]=i;
    int k,s,l;
    for(int i=1;i<=k;i++)
    {
        cin>>k>>s>>l;
        t[i].key=k;
        t[i].st=s;
        t[i].ed=s+l;
    }
    //时间模拟
    for(int i=1;i<=100101;i++)
    {

    }
    //输出
    testout();
    return 0;
}
