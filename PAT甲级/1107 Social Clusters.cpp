//注意容器的排序
//并查集
//specify指定,详述
//hence从此,因此
//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1005;
/*
typedef struct node{
vector<int> hobby;
}
*/
typedef struct node
{
	vector<int> people;
}node;
node hobby[maxn];
//并查集无环
//父节点只有一个
int father[maxn];
//利用child数组寻找每个并查集的大小
vector<int> child[maxn];
//标记数组
bool vis[maxn];
//并查集数量标记
vector<int> l;
int N;
void initiate()
{
	for (int i = 1; i <= N; i++)
	{
		father[i] = i;
	}
}
//找父节点顺便压缩路径
int findfather(int root)
{
	if (father[root] == root)
		return root;
	return father[root] = findfather(father[root]);
}
//可能不需要压缩路径
//是否需要压缩路径
void createfather()
{
	for (int i = 1; i <= maxn; i++)
	{
		if(hobby[i].people.size()>=2)
		for (int j = 0; j < hobby[i].people.size() - 1; j++)
		{
			int f1 = findfather(hobby[i].people[j]);
			int f2 = findfather(hobby[i].people[j + 1]);
			if (f1 != f2)
				father[f1] = f2;
			child[f2].push_back(f1);
		}
	}
}
void dfs(int root, int &length)
{
	if (child[root].size() == 0)
		return;
	for (int i = 0; i<child[root].size(); i++)
	{
		if (vis[i] == false)
		{
			vis[i] = true;
			length++;
			dfs(i, length);
		}
	}
}

void find_num_ufs()
{
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (father[i] == i)
		{
			int length = 1;
			vis[i] = true;
			dfs(i, length);
			l.push_back(length);
			ans++;
		}
	}
	sort(l.begin(), l.end());
	printf("%d\n", ans);
	//cout << ans << endl;
	for (int i = 0; i<l.size(); i++)
	{
		cout << l[i];
		if (i != l.size() - 1)
			printf(" ");
			//cout << " ";
	}
}
int main()
{
	//cin >> N;
	scanf_s("%d", &N);
	initiate();
	for (int i = 1; i <= N; i++)
	{
		int k;
		//cin >> k;
		scanf_s("%d:", &k);
		for (int j = 0; j<k; j++)
		{
			int h;
			//cin >> h;
			scanf_s("%d", &h);
			hobby[h].people.push_back(i);
		}
	}
	createfather();
	fill(vis + 1, vis + 1 + N, 0);
	find_num_ufs();
	return 0;
}
/*
8
3 2 7 10
1 4
2 5 3
1 4
1 3
1 4
4 6 8 1 5
1 4
*/
