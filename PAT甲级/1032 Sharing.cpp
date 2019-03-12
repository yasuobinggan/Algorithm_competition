#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef struct NODE{
    char data;
    int next;
    bool flag;//结点是否在第一条链表中出现
}NODE;
NODE node[maxn];
int main()
{
    //初始化
    for(int i=0;i<maxn;i++)
    {
        node[i].flag=false;
    }
    int s1,s2,n;//s1,s2分别为两条链表的首地址
    scanf("%d%d%d",&s1,&s2,&n);
    for(int i=0;i<n;i++)
    {
        int address,next;
        char data;

        scanf("%d %c %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
    }

    int p;
    //遍历第一条链
    for(p=s1;p!=-1;p=node[p].next)
    {
        node[p].flag=true;
    }
    for(p=s2;p!=-1;p=node[p].next)
    {
        if(node[p].flag==true)
            break;
    }
    if(p!=-1)
    {
        printf("%05d\n",p);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
