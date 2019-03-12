#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef struct NODE{
    int address;
    int key;
    int next;
    int flag;
}NODE;
NODE node[maxn];
bool cmp(NODE a,NODE b)
{
    if(a.flag!=b.flag)
        return a.flag>b.flag;
    else
        return a.key<b.key;
}
int main()
{
    int n,s;

    //初始化
    for(int i=0;i<n;i++)
    {
        node[i].flag=0;
    }
    //输入
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)
    {
        int address,key,next;
        scanf("%d",&address);
        node[address].address=address;
        scanf("%d %d",&node[address].key,&node[address].next);
    }
    //遍历标记在链上的节点
    //找到头节点的位置
    int p;
    /*
    for(int i=0;i<n;i++)
    {
        if(node[i].address==s)
        {
            p=s;
            break;
        }
    }
    */
    int ans=0;
    for(p=s;p!=-1;p=node[p].next)
    {
        node[p].flag=1;
        ans++;
    }
    sort(node,node+n,cmp);
    //整理链next的指向

    //输出(直接整理next的指向)
    printf("%d %05d\n",ans,node[0].address);
    p=node[0].address;
    for(int i=0;i<ans;i++)
    {
        printf("%05d %d %05d",node[i].address,node[i].key,node[i+1].address);
    }
    return 0;
}
