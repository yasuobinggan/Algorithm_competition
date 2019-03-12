//有错误 
//经过了一段时间思考程序的逻辑 
//建树，判断先序遍历，判断镜像遍历，输出
//建树，判断先序遍历，判断镜像遍历，输出
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
typedef struct Node {
	int data;
	struct Node *ltree;
	struct Node *rtree;
}Node, *Pnode;
const int maxl = 1e3;
int N;
int inputorder[maxl];
int preorder[maxl];
int mirrororder[maxl];

void create_bst(Pnode &root, char data)
{
	if (root == NULL)
	{
		root = (Pnode)malloc(sizeof(Node));
		root->data = data;
		root->ltree = NULL;
		root->rtree = NULL;
		return;
	}
	else if (data<root->data)
	{
		create_bst(root->ltree, data);
	}
	else if(data>=root->data)
	{
		create_bst(root->rtree, data);
	}
}
void pre_travel(Pnode root, int &curindex)
{
	if (root == NULL)
	{
		return;
	}
	
	preorder[curindex++]=root->data;
	pre_travel(root->ltree,curindex);
	pre_travel(root->rtree, curindex);

}
void mirror_pre_travel(Pnode root,int &curindex)//镜像树的先序遍历 
{
	if (root == NULL)
	{
		return;
	}

	mirrororder[curindex++] = root->data;
	mirror_pre_travel(root->rtree,curindex);
	mirror_pre_travel(root->ltree, curindex);
}
void post_travel(Pnode root,int &curindex)
{
	if (root == NULL)
		return;
	
	post_travel(root->ltree,curindex);
	post_travel(root->rtree,curindex);
	
	if (curindex == N-1)
	{
		cout << root->data << endl;
	}
	else
	{
		cout << root->data<<" ";
	}
	++curindex; 
}
void mirror_post_travel(Pnode root,int &curindex)
{
	if (root == NULL)
		return;
	
	mirror_post_travel(root->rtree,curindex);
	mirror_post_travel(root->ltree,curindex);
	
	if (curindex == N-1)
	{
		cout << root->data << endl;
	}
	else
	{
		cout << root->data<<" ";
	}
	++curindex;
}
bool judge(int a[],int b[])
{
	for (int i = 0; i < N; i++)
	{
		if (a[i] != b[i])
			return false;
	}
	return true;
}
int main()
{
	cin >> N;
	Pnode root;
	root = NULL;

	for (int i = 0; i<N; i++)
	{
		cin >> inputorder[i];
		create_bst(root, inputorder[i]);
	}
	
	int curlen = 0;
	pre_travel(root, curlen);
	curlen = 0;
	mirror_pre_travel(root, curlen);
	
	if (judge(preorder, inputorder) || judge(mirrororder, inputorder))
	{
		cout << "YES" << endl;
		curlen = 0;
		if(judge(preorder,inputorder)==true) 
			post_travel(root, curlen);
		else
			mirror_post_travel(root,curlen);
	} 
	else
		cout << "NO" << endl;
	return 0;
}

/*
7
8 6 5 7 10 8 11

7
8 10 11 8 6 7 5
*/
