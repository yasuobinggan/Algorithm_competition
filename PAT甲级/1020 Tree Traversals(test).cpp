//递归建树
//增加标记有助于更加清晰的解决问题
//两个标记构建一个区间
//增加标记有助于解题
#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
typedef struct NODE{
    int data;
    struct NODE *ltree;
    struct NODE *rtree;
}node,*pnode;
int n;
vector<int> inorder;
vector<int> postorder;
vector<int> layerorder;

int find_root(int number,int instart,int inend)
{
    for(int i=instart;i<=inend;i++)
    {
        if(inorder[i]==number)
            return i;
    }
}

void createtree(pnode &root,int poststart,int postend,int instart,int inend)
{
    //递归边界+return
    if(poststart>postend)
    {
        root=NULL;
        return;
    }

    root=(pnode)malloc(sizeof(node));
    root->data=postorder[postend];


    int position=find_root(postorder[postend],instart,inend);
    int Llen=position-instart;
    int Rlen=inend-position;

    createtree(root->ltree,poststart,poststart+Llen-1,instart,position-1);
    createtree(root->rtree,postend-Rlen,postend-1,position+1,inend);
}

void layertravel(pnode root)
{
    queue<pnode> q;
    q.push(root);
    while(!q.empty())
    {
        pnode curnode=q.front();
        layerorder.push_back(curnode->data);
        q.pop();
        if(curnode->ltree!=NULL)
        {
            q.push(curnode->ltree);
        }
        if(curnode->rtree!=NULL)
        {
            q.push(curnode->rtree);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int number;
        scanf("%d",&number);
        postorder.push_back(number);
    }
    for(int i=0;i<n;i++)
    {
        int number;
        scanf("%d",&number);
        inorder.push_back(number);
    }

    pnode root;
    createtree(root,0,n-1,0,n-1);

    layertravel(root);
    for(int i=0;i<n;i++)
    {
        printf("%d",layerorder[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    return 0;
}
