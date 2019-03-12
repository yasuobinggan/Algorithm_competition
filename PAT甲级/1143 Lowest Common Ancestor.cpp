//recursively递归
//descendant后代
//bst
//线索化二叉树？
//bfs解决
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
typedef struct NODE{
    int vis;
    int data;
    struct NODE *father;
    struct NODE *lchild;
    struct NODE *rchild;
}node,*pnode;

int M,N;

void createtree(pnode father,pnode &root,int d)
{
    if(root==NULL)
    {
        //pnode curroot;
        root=(pnode)malloc(sizeof(node));
        root->data=d;
        root->vis=0;
        root->lchild=root->rchild=NULL;
        //root=curroot;
        root->father=father;

        return;
    }
    if(d<root->data)
    {
        createtree(root,root->lchild,d);
    }
    else
    {
        createtree(root,root->rchild,d);
    }
}
void search_node(pnode root,int u,int v,int &flagu,int &flagv,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==u)
    {
        flagu=true;
        pnode p=root;
        while(p!=NULL)
        {
            if(p->vis==1)
            {
                ans=p->data;
                return;
                //break;
            }
            p->vis=1;
            p=p->father;
        }
    }

    if(root->data==v)
    {
        flagv=true;
        pnode p=root;
        while(p!=NULL)
        {
            if(p->vis==1)
            {
                ans=p->data;
                return;
                //break;
            }
            p->vis=1;
            p=p->father;
        }
    }


    search_node(root->lchild,u,v,flagu,flagv,ans);
    search_node(root->rchild,u,v,flagu,flagv,ans);
}

void search_ans(pnode root,int u,int v)
{
    int flagu=false,flagv=false;
    //获取父节点值
    int ans=0;
    search_node(root,u,v,flagu,flagv,ans);
    if(flagu&&flagv)
    {
        if(ans!=u&&ans!=v)
        {
            printf("LCA of %d and %d is %d.\n",u,v,ans);
        }
        if(ans==u)
        {
            printf("%d is an ancestor of %d.\n",u,v);
        }
        if(ans==v)
        {
            printf("%d is an ancestor of %d.\n",v,u);
        }
    }
    if(flagu==false&&flagv==true)
    {
        printf("ERROR: %d is not found.\n",u);
    }
    if(flagu==true&&flagv==false)
    {
        printf("ERROR: %d is not found.\n",v);
    }
    if(flagu==false&&flagv==false)
    {
        printf("ERROR: %d and %d are not found.\n",u,v);
    }
}

int main()
{
    scanf("%d%d",&M,&N);
    pnode root=NULL;
    for(int i=0;i<N;i++)
    {
        int d;
        scanf("%d",&d);
        createtree(NULL,root,d);
    }
    for(int i=0;i<M;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        search_ans(root,u,v);
    }
    //test(root);
    return 0;
}
