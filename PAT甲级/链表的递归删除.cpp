#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
}node,*linklist;
const int INF=(1<<30)-1;
const int maxn=1005;
int N;
void construct_linklist(linklist &L)
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int data;
        cin>>data;
        linklist p=(linklist)malloc(sizeof(node));
        p->data=data;
        p->next=L->next;
        L->next=p;
    }
}
void dl(linklist &pre,linklist &p)
{
    if(p->next==NULL)
    {
        pre->next=p->next;
        free(p);
        cout<<"删除成功"<<" ";
        return;
    }
    dl(pre->next,p->next);
    pre->next=p->next;
    free(p);
    cout<<"删除成功"<<" ";
}
void travel(linklist pre)
{
    linklist p=pre->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    linklist L;
    L=(linklist)malloc(sizeof(node));
    L->next=NULL;
    construct_linklist(L);
    travel(L);
    dl(L,L->next);
    travel(L);
    return 0;
}
