//volume体积,卷,量,大量
//region地区,层
//slice薄片
//resolution分辨率,解决
//threshold门槛,入口
//connected连接的,有关系的,有联系的counted
//pixel像素
//constant持续的
//obtain获得


//一定先判断是否越界
//dfs,bfs的选择
//通过当前问题的规模和实际判断选择合适的遍历方式
//三维BFS
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
//1表示被破坏,0表示正常
//M*N矩阵
typedef struct node {
	int i;
	int j;
	int k;
}node;
const int maxa = 1291, maxb = 133, maxc = 65;
int M, N, L, T;
int martix[maxc][maxa][maxb];
bool vis[maxc][maxa][maxb];
int dir[6][3] = {
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1,
};
int ans = 0;

int bfs(int i, int j, int k)
{
	int cans = 0;
	queue<node> q;
	node newnode;
	newnode.i = i; newnode.j = j; newnode.k = k;
	q.push(newnode);
	while (!q.empty())
	{
		node curnode = q.front();
		cans++;
		q.pop();
		for (int w = 0; w<6; w++)
		{
			int newi = curnode.i + dir[w][0];
			int newj = curnode.j + dir[w][1];
			int newk = curnode.k + dir[w][2];

			if (0 <= newi && newi < L && 0 <= newj && newj < M && 0 <= newk && newk < N)
			{
				if (vis[newi][newj][newk] == false && martix[newi][newj][newk] == 1)
				{
					vis[newi][newj][newk] = true;
					node pushnode;
					pushnode.i = newi; pushnode.j = newj; pushnode.k = newk;
					q.push(pushnode);
				}
			}


		}
	}
	return cans;
}
int main()
{
	//cin >> M >> N >> L >> T;
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for (int i = 0; i<L; i++)
	{
		for (int j = 0; j<M; j++)
		{
			for (int k = 0; k<N; k++)
			{

				scanf("%d", &martix[i][j][k]);
				//cin >> martix[i][j][k];
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i<L; i++)
	{
		for (int j = 0; j<M; j++)
		{
			for (int k = 0; k<N; k++)
			{
				if (martix[i][j][k] == 1 && vis[i][j][k] == false)
				{
					vis[i][j][k] = true;
					int curans = bfs(i, j, k);
					//cout << curans << endl;
					if (curans >= T)
					{
						ans += curans;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}
