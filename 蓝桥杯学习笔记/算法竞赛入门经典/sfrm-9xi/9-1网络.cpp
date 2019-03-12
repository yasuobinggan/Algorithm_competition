/*
	根据网络上的记忆化搜索修改
	记忆化搜索是填表 
*/
#include <cstdio>
#include <cstring>

const int N = 105;
const int M = 4;
const int dir[M][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int G[N][N];
int dp[N][N];
char name[N * 10];
int r, c;

int Max (const int a, const int b) { return a > b? a: b; }

int DP (int x, int y) {

	int& ans = dp[x][y];
	if (ans != -1)
		return ans;
	//if (ans == -1)      //这个点走不出去
	ans = 1;
	int newx, newy;
	for (int i = 0;  i < M; i++) {
		newx = x + dir[i][0];
		newy = y + dir[i][1];
		if (newx < 0 || newx >= r || newy < 0 || newy >= c)
			continue;
		if (G[x][y] > G[newx][newy])
			ans = Max (ans, DP (newx, newy) + 1);  //从这个位置开始四个方向的最长长度取最大值 
	}
//	if (ans == -1)      //这个点走不出去
//		ans = 1;
	return ans;	
}

int main () {
	
	int t;
	//scanf ("%d", &t);
	//while (t--) {

		scanf ("%d%d", &r, &c);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf ("%d", &G[i][j]);
		
		memset (dp, -1, sizeof (dp));
		int ans = -1;
				for (int i = 0; i < r; i++) //从每个位置开始走都是有可能的取得最长路径
			for (int j = 0; j < c; j++)
				ans = Max (ans, DP(i, j));
		printf ("%s: %d\n", name, ans);	
	//}
	return 0;
}
