#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
    char data;
    struct Node* ltree;
    struct Node* rtree;
}Node,*PNode;
void construct(PNode &root,string inorder,string preorder,int inst,int ined,int prest,int preed)
{
    if(prest>preed)
    {
        root=NULL;
        return;
    }
    root=(PNode)malloc(sizeof(Node));
    root->data=preorder[prest];
    int i;
    for(i=inst;i<=ined;i++)
    {
        if(inorder[i]==preorder[prest])
        {
            break;
        }
    }
    int ltlength=i-inst;
    int rtlength=ined-i;
    construct(root->ltree,inorder,preorder,inst,i-1,prest+1,prest+ltlength);
    construct(root->rtree,inorder,preorder,i+1,ined,prest+ltlength+1,preed);
}
void post_travel(PNode root)
{
    if(root==NULL)
        return;
    post_travel(root->ltree);
    post_travel(root->rtree);
    cout<<root->data;
}
int main()
{
    string inorder;
    string preorder;

    cin>>preorder;
    cin>>inorder;

    PNode root;
    construct(root,inorder,preorder,0,inorder.size()-1,0,preorder.size()-1);
    post_travel(root);
    cout<<endl;
    return 0;
}
/*
ABDGCEFH
DGBAECHF
*/
