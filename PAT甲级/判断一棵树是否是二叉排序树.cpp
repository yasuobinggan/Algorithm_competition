#include<bits/stdc++.h>
using namespace std;
typedef struct btnode{
    int data;
    struct btnode *lchild;
    struct btnode *rchild;
}btnode,*bt;
const int INF=(1<<30)-1;
const int maxn=1005;
int N;
int pre=-INF;
void insert_tree(bt &root,int x)
{
    if(root==NULL)
    {
        root=(bt)malloc(sizeof(btnode));
        root->data=x;
        root->lchild=NULL;
        root->rchild=NULL;
        return;
    }
    if(x<root->data)
    {
        insert_tree(root->lchild,x);
    }
    else
        insert_tree(root->rchild,x);
}
bt construct_tree(bt &root)
{
    int x;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>x;
        insert_tree(root,x);
    }
    return root;
}
void inorder(bt root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
}
bool judge(bt root)
{
    if(root==NULL)
        return true;
    else
    {
        bool bl=judge(root->lchild);
        if(bl==false||pre>root->data)
            return false;
        pre=root->data;
        bool br=judge(root->rchild);
        return br;
    }
}
int main()
{
    bt root=NULL;
    root=construct_tree(root);
    inorder(root);
    if(judge(root))
        cout<<"YES"<<endl;
    return 0;
}
