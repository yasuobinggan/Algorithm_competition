//invert反转 
//indicys
//静态二叉树层序遍历一定要对节点进行判断 
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxl = 15;
int N;
typedef struct node {
	int ltree;
	int rtree;
}node;
node tree[maxl];
bool vis[maxl];
vector<int> inorder;
vector<int> layerorder;
int findroot()
{
	for (int i = 0; i<N; i++)
	{
		if (vis[i] != true)
			return i;
	}
	return -1;
}

void layertravel(int root)
{
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int curroot = q.front();
		layerorder.push_back(curroot);
		q.pop();
		if(tree[curroot].rtree!=-1)
			q.push(tree[curroot].rtree);
		if (tree[curroot].ltree != -1)
			q.push(tree[curroot].ltree);
	}
}

void intravel(int root)
{
	if (root == -1)
		return;
	intravel(tree[root].rtree);
	inorder.push_back(root);
	intravel(tree[root].ltree);
}
int main()
{
	cin >> N;
	fill(vis, vis + maxl, 0);
	for (int i = 0; i<N; i++)
	{
		char l, r;
		cin >> l >> r;
		if (l != '-')
		{
			tree[i].ltree = l - '0';
			vis[tree[i].ltree] = true;
		}
		else
			tree[i].ltree = -1;
		if (r != '-')
		{
			tree[i].rtree = r - '0';
			vis[tree[i].rtree] = true;
		}
		else
			tree[i].rtree = -1;
	}
	int root = findroot();
	//cout<<root<<endl;
	layertravel(root);
	for (int i = 0; i<layerorder.size(); i++)
	{
		cout << layerorder[i];
		if (i != layerorder.size() - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	intravel(root);
	for (int i = 0; i<inorder.size(); i++)
	{
		cout << inorder[i];
		if (i != inorder.size() - 1)
		{
			cout << " ";
		}
	}
	return 0;
}
