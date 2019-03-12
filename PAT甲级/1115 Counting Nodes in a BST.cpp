#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int data;
	int layer;
	struct node* ltree;
	struct node* rtree;
}node,*pnode;
int N;
const int maxl=1000+5;
int l[maxl];
void createbst(pnode &root,int v)
{
	if(root==NULL)
	{
		root=(pnode)malloc(sizeof(node));
		root->data=v;
		root->ltree=root->rtree=NULL;
		return;
	}
	else if(root->data<=v)
	{
		createbst(root->ltree,v);
	}
	else
	{
		createbst(root->rtree,v);
	}
}
void bfs(pnode root)
{
	queue<pnode> q;
	root->layer=0;
	q.push(root);

	while (!q.empty())
	{
		pnode curroot = q.front();
		l[curroot->layer]++;
		q.pop();
		if (curroot->ltree)
		{
			curroot->ltree->layer=curroot->layer+1;
			q.push(curroot->ltree);
		}
		if (curroot->rtree)
		{
			curroot->rtree->layer=curroot->layer+1; 
			q.push(curroot->rtree);
		}
	}
}
void getans(int &a,int &b,int &c)
{
	int len=0;
	while(l[len]!=0)
		len++;
	a=l[len-1];
	b=l[len-2];
	c=a+b;
}
int main()
{
	pnode root=NULL;
	fill(l,l+maxl,false);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int v;
		cin>>v;
		createbst(root,v);
	}
	bfs(root);
	int a,b,c;
	getans(a,b,c);
	cout<<a<<" + "<<b<<" = "<<c; 
	return 0;
 } 
