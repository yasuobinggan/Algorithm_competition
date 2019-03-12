///buy一个表,sell一个表:修改
#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;
struct Node{
    char op[maxn];
    double p;
    int s;
    bool flag;
    Node(char _op[],double _p,int _s,bool _flag)
    {
        op=_op;
        p=_p;
        s=_s;
        flag=_flag;
    }
};
Node b[maxn];
Node s[maxn];
//vector<Node> gus;
bool cmp(Node a,Node b)
{
    return a.p<b.p;
}
int main()
{
    char op[maxn];
    double p;
    int s;
    bool flag;
    while(scanf("%s %f %d",op,&p,&s)!=EOF)
    {
        if(op[0]=='b')
        {

        }
        if(op[0]=='s')
        {

        }
        if(op[0])
        (Node(op,p,s));
    }
    sort(gus.begin(),gus.end(),cmp);

    for(int i=0;i<)
    return 0;
}
