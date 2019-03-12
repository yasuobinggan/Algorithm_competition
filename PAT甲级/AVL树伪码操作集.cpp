//AVL树的一些伪码 
//左旋,右旋代码的完整性
//建树的调整高度和判断平衡因子 
#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int v;//节点的值 
	int height;//节点的高度 
	struct node* ltree;
	struct node* rtree; 
}node,*pnode;
//新建结点时初始化高度为1 
int getHeight(pnode node)
{
	if(node==NULL)
		return 0;
	return node->height; 
}
int getBalanceFactor(pnode node)//利用一个函数计算平衡因子 
{
	return getHeight(node->ltree)-getHeight(node->rtree);
} 
void updateHeight(pnode &node)
{
	node->height=max(getHeight(node->ltree),getHeight(node->rtree))+1;
} 
void L(pnode &root)//左旋
{
	pnode temp;
	temp=root->rtree;
	
	root->ltree=temp->ltree;
	temp->ltree=root;
	//自下而上更新节点高度 
	updateHeight(root);
	updateHeight(temp);
	
	root=temp;//不要遗忘 
 } 
void R(pnode &root)//右旋
{
	pnode temp;
	temp=root->ltree;
	
	root->ltree=temp->rtree;
	temp->rtree=root;
	//
	updateHeight(root);
	updateHeight(temp);
	
	root=temp;
	 
 } 
void insert(pnode &root,int v)
{
	if(root==NULL)//递归边界 
	{
		root=(pnode)malloc(sizeof(node));
		root->v=v;
		root->height=1;//节点高度初始化为1
		root->ltree=root->rtree=NULL;
		return; 
	}
	if(v<root->v)
	{
		insert(root->ltree,v);
		//由下向上调整搜索树 
		updateHeight(root);//更新树高
		if(getBalanceFactor(root)==2)//一定是l型的,判断是否平衡 
		{
			if(getBalanceFactor(root->ltree)==1)//ll型 
			{
				R(root);
			}
			else if(getBalanceFactor(root->ltree)==-1)//lr型 
			{
				L(root->ltree);
				R(root);
			}
		 } 
	}
	else
	{
		insert(root->rtree,v);
		//由下向上调整搜索树 
		updateHeight(root);
		if(getBalanceFactor(root)==-2)
		{
			if(getBalanceFactor(root->rtree)==-1)//rr型 
			{
				L(root);
			}
			else if(getBalanceFactor(root->rtree)==1)//rl型 
			{
				R(root->rtree);
				L(root);
			 } 
		}
	}
}
pnode createtree(int n)//返回头节点,构建BST树同样需要学习 
{
	pnode root=NULL;//树根节点 
	for(int i=0;i<n;i++)
	{
		int data;
		cin>>data;
		insert(root,data);
	}
	cout<<root->v;
	return root;
 } 
 int main()
 {
 	int N;
 	cin>>N;
 	createtree(N);
	 return 0;
 }
