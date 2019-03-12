/*
    一.按序输出
        排序后处理
        处理后排序
    stack 可否用迭代器访问内部元素
    标记数组时使用头坐标和尾坐标更好
*/
#include<bits/stdc++.h>
using namespace std;
const int maxl = 1e2 + 5;
typedef struct node {
	int weight;
	vector <int>child;
}node;
int N, M, S;//节点总数；非叶节点总数，目标权重
node tree_node[maxl];//数组存树
int curlen_wei[maxl];
//给指针域排序
bool cmp(int a,int b)
{
    return tree_node[a].weight>tree_node[b].weight;
    //return a>b;
}

void createtree(int index, int k)
{
	int c_child;
	for (int i = 0; i < k; i++)
	{

		cin >> c_child;
		tree_node[index].child.push_back(c_child);

	}
}

void dfs(int root, int curwei, int curlen_wei_len)
{
	if (curwei > S)
		return;
	if (tree_node[root].child.size()==0 && curwei == S)
	{
		for (int i = 0; i<curlen_wei_len; i++)
		{
			cout << curlen_wei[i];
			if(i!=curlen_wei_len-1)
                cout<<" ";

		}
		cout << endl;
		return;
	}
	for (int i = 0; i<tree_node[root].child.size(); i++)
	{

		curlen_wei[curlen_wei_len] = tree_node[tree_node[root].child[i]].weight;
		dfs(tree_node[root].child[i], curwei + tree_node[tree_node[root].child[i]].weight, curlen_wei_len + 1);

	}
}
int main()
{

	cin >> N >> M >> S;

	for (int i = 0; i<N; i++)
	{

		cin >> tree_node[i].weight;
	}
	for (int i = 0; i<M; i++)
	{
		int id, K;

		cin >> id >> K;
		createtree(id, K);
		sort(tree_node[id].child.begin(),tree_node[id].child.end(),cmp);
	}
	int curwei = tree_node[0].weight;

	curlen_wei[0] = tree_node[0].weight;
	int curlen_wei_len = 1;
	dfs(0, curwei, curlen_wei_len);
	return 0;

}
/*
4 1 2
1 1 1 1
00 3 01 02 03
***********************************
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19
*/
/*
1 1
1 1
1 1
*/
