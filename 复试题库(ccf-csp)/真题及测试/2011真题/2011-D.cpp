//1:建立哈夫曼树
//2:建堆
//方法1//priority的排序方式
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    int data;
    struct Node* ltree;
    struct Node* rtree;
    /*
    friend bool operator<(Node a,Node b)
    {
        return a.data > b.data;
    }
    */
}Node,*PNode;
struct cmp{
    bool operator () (PNode a,PNode b)
    {
        return a->data > b->data;
    }
};
//const int maxn=70;
priority_queue<PNode,vector<PNode>,cmp> q;
//priority_queue<int,vector<int>,greater<int>> q;
PNode construct()
{
    while(!q.empty())
    {
        PNode root1=q.top();q.pop();
        PNode root2=q.top();q.pop();
        PNode root=(PNode)malloc(sizeof(Node));
        //cout<<root1->data<<" "<<root2->data<<endl;
        root->data=root1->data+root2->data;
        root->ltree=root1;
        root->rtree=root2;
        q.push(root);
        if(q.size()==1)
            return root;
    }
}
void cal_wpl(PNode root,int depth,int &ans)
{
    if(root==NULL)
        return;
    if(root->ltree==NULL&&root->rtree==NULL)
    {
        ans+=depth*root->data;
    }
    cal_wpl(root->ltree,depth+1,ans);
    cal_wpl(root->rtree,depth+1,ans);
}
void testout(PNode root)
{
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    testout(root->ltree);
    testout(root->rtree);
}
int main()
{
    int n;
    cin>>n;
    int value;
    for(int i=1;i<=n;i++)
    {
        cin>>value;

        PNode root=(PNode)malloc(sizeof(Node));
        root->data=value;
        root->ltree=NULL;
        root->rtree=NULL;

        q.push(root);
    }
    PNode root=construct();
    //testout(root);
    //cout<<endl;
    int ans=0;
    cal_wpl(root,0,ans);
    cout<<ans<<endl;
    return 0;
}
/*
8
7 19 2 6 32 3 21 10
*/
