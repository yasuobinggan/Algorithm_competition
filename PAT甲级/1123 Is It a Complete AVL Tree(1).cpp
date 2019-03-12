//疑问为什么不用&引用也修改了root->index的值
//判断一棵动态树是完全二叉树
//数组写平衡二叉树
//左旋，右旋不能忘初始化指针
//propetry特性,属性,财产
//rotation旋转,转动

//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef struct node {
	int data;
	int height;
	int index;//与完全二叉树下标对应 
	struct node* ltree;
	struct node* rtree;
}node, *pnode;
const int maxl = 25;
int N;//节点数 
vector<int> layerorder;
vector<int> judgeorder;
//int l[maxl];//记录每一层上的节点数，根据此数组判断是否是完全二叉树 
void bfs(pnode root)
{
	queue<pnode> q;
	//queue<int> judgeq;
	root->index=1; 
	q.push(root);

	while (!q.empty())
	{
		pnode curroot = q.front();
		layerorder.push_back(curroot->data);
		judgeorder.push_back(curroot->index);
		q.pop();
		if (curroot->ltree)
		{
			curroot->ltree->index=((curroot->index)*2);
			//judgeq.push(curroot
			q.push(curroot->ltree);
		}
		if (curroot->rtree)
		{
			curroot->rtree->index=((curroot->index)*2+1); 
			q.push(curroot->rtree);
		}
	}
}
int judge(int n)
{
	for(int i=0;i<n;i++)
	{
		//cout<<judgeorder[i]<<"　"; 

		if(judgeorder[i]!=i+1)
			return false;
	}

	return true;
}
/*
void dfs_test(pnode root)
{
	if(root==NULL)
		return;
	cout<<root->index<<" ";
	dfs_test(root->ltree);
	dfs_test(root->rtree);

}
*/
//！！！！！！！！
int getheight(pnode root)
{
	if (root==NULL)
	{
		return 0;
	}
	return root->height;
}
void updateheight(pnode &root)
{
	root->height = max(getheight(root->ltree), getheight(root->rtree)) + 1;
}
int getbalancefactor(pnode root)
{
	return getheight(root->ltree) - getheight(root->rtree);
}
void l(pnode &root)//左旋 
{
	pnode temp;
	temp = root->rtree;
	root->rtree = temp->ltree;
	temp->ltree = root;
	//自下而上更新高度 
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void r(pnode &root)//右旋 
{
	pnode temp;
	temp = root->ltree;
	root->ltree = temp->rtree;
	temp->rtree = root;
	updateheight(root);
	updateheight(temp);
	root = temp;
}
void insert(pnode &root, int v)
{
	if (root == NULL)//递归边界 
	{
		root = (pnode)malloc(sizeof(node));
		root->data = v;
		root->height = 1;//初始化节点高为 1 
		root->ltree = NULL;
		root->rtree = NULL;
		return;
	}
	if (v >= root->data)
	{
		insert(root->rtree, v);
		//插入后更新根节点的高度 
		updateheight(root);
		if (getbalancefactor(root) == -2)
		{
			//只对右子树判断因为右子树一定存在
			if (getbalancefactor(root->rtree) == -1)//rr型
				l(root);
			else if (getbalancefactor(root->rtree) == 1)//rl型
			{
				r(root->rtree);
				l(root);
			}
		}
	}
	else if (v<root->data)
	{
		insert(root->ltree, v);
		//插入后更新根节点的高度
		updateheight(root);
		if (getbalancefactor(root) == 2)
		{
			//只对左子树判断因为左子树一定存在
			if (getbalancefactor(root->ltree) == 1)//ll型
				r(root);
			else if (getbalancefactor(root->ltree) == -1)//lr型
			{
				l(root->ltree);
				r(root);
			}
		}
	}
}
pnode createtree(int n)
{
	pnode root;//动态树的根节点
	root = NULL;
	for (int i = 0; i<n; i++)
	{
		int v;
		cin >> v;
		insert(root, v);
	}
	return root;
}
int main()
{
	cin >> N;

	pnode root = createtree(N);
	bfs(root);
	for (int i = 0; i<layerorder.size(); i++)
	{
		cout << layerorder[i];
		if (i != layerorder.size() - 1)
			cout << " ";
	}
	
	if (judge(N))
	{	
		cout << endl << "YES";
	}
	else
		cout <<endl<< "NO";
	//dfs_test(root);
	return 0;
}
/*
5
88 70 61 63 65
*/
