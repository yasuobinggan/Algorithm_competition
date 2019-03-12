//错误 
//可以bfs直接返回最后一个节点，
//if(q.size()==1&&tree[q.front()].lchild==-1&&tree[q.front().rchild==-1])
//	标记位记录 
#include<bits/stdc++.h>
using namespace std;
#define maxl 20 

typedef struct node{
    int index;
    int lchild;
    int rchild;
}node;

node tree[maxl];
bool vis[maxl];
int N;
vector<int>layerorder;
int find_root()
{
    for(int i=0;i<N;i++)
    {
        if(vis[i]==false)
            return i;
    }
}
/*
int find_lastroot()
{
	int max=-1;
	int lastroot;
	for(int i=0;i<N;i++)
	{
		if(tree[i].index>max)
		{
			max=tree[i].index;
			lastroot=i;		
		}
	}
	return lastroot;
}
*/
void bfs(int root,int &lastroot)
{
	queue<int> q;
	tree[root].index=1;
	q.push(root);
	
	while (!q.empty())
	{
		int curroot = q.front();
		if(q.size()==1&&tree[q.front()].lchild==-1&&tree[q.front()].rchild==-1)
			lastroot=q.front(); 
		layerorder.push_back(tree[curroot].index);
		q.pop();
		if (tree[curroot].lchild!=-1)
		{
			tree[tree[curroot].lchild].index=tree[curroot].index*2;
			q.push(tree[curroot].lchild);
		}
		if (tree[curroot].rchild!=-1)
		{
			tree[tree[curroot].rchild].index=tree[curroot].index*2+1;
			q.push(tree[curroot].rchild);
		}
	}
}
bool judge()
{
	
	for(int i=0;i<layerorder.size();i++)
	{
		//cout<<layerorder[i]<<" ";
		if(layerorder[i]!=i+1)
			return false;
	}
	
	return true;
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char l,r;
        cin>>l>>r;
        
        if(l=='-')
            tree[i].lchild=-1;
        else
        {
            tree[i].lchild=l-'0';
            vis[tree[i].lchild]=true;
        }

        if(r=='-')
            tree[i].rchild=-1;
        else
        {
            tree[i].rchild=r-'0';
            vis[tree[i].rchild]=true;
        }

    }
    int root=find_root();
    int lastroot=-1;
    bfs(root,lastroot);
    if(judge())
    {
    	cout<<"YES"<<" "<<lastroot;
	}
	else
	{
		cout<<"NO"<<" "<<root;
	}
    return 0;
}
