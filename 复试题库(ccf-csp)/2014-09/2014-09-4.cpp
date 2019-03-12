//对dfs适当剪枝
//bfs一定获得最优解
//dfs搜索解空间
//贪心
#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;
const int maxn = 1005;
const int INF = (1 << 30) - 1;
int G[maxn][maxn];
bool visited[maxn][maxn];
int dir[4][2] = { 1,0,0,1,0,-1,-1,0 };
struct Node {
	int x, y;
	int weight;
};
Node w[maxn];
int n, m, k, d;
int ans = 0;
//dfs图注意边界 标记
void dfs(int x, int y, int weight, int curans, int &pans)
{
	//剪枝
	if (curans>pans)
		return;
	if (G[x][y] == 1)
	{
		if (curans<pans)
		{
			pans = curans;
			//cout <<"搜索中:"<<x<<" "<<y<<" "<< pans<<endl;
		}
		return;
	}

	for (int i = 0; i<4; i++)
	{
		int curx = x + dir[i][0];
		int cury = y + dir[i][1];
		if (1 <= curx&&curx <= n && 1 <= cury&&cury <= n)
		{
			if (G[curx][cury] != 3 && visited[curx][cury] == false)
			{
				visited[curx][cury] = 1;
				dfs(curx, cury, weight, curans + weight, pans);
				visited[curx][cury] = 0;
			}
		}
	}
}
int main()
{
	memset(G, 0, sizeof(G));
	memset(visited, false, sizeof(visited));
	cin >> n >> m >> k >> d;
	int x, y, weight;
	//分店
	for (int i = 0; i<m; i++)
	{
		cin >> x >> y;
		G[x][y] = 1;
	}
	//客户
	for (int i = 0; i<k; i++)
	{
		cin >> x >> y >> weight;
		G[x][y] = 2;
		w[i].x = x;
		w[i].y = y;
		w[i].weight = weight;
	}
	//禁止通行
	for (int i = 0; i<d; i++)
	{
		cin >> x >> y;
		G[x][y] = 3;
	}
	for (int i = 0; i<k; i++)
	{
		int pans = INF;
		visited[w[i].x][w[i].y] = 1;
		dfs(w[i].x, w[i].y, w[i].weight, 0, pans);
		visited[w[i].x][w[i].y] = 0;
		//cout << pans << endl;
		ans += pans;
	}
	cout << ans;
	return 0;
}
/*
10 2 3 3
1 1
8 8
1 5 1
2 3 3
6 7 2
1 2
2 2
6 8
*/
/*
5 1 1 0
4 1
1 1 5
*/
