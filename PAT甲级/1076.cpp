//最后一条有错误 
#include<bits/stdc++.h> 
using namespace std;
#define maxn 1000
typedef struct node {
	int user;
	int layer;
}node;
int N, L;
int K, k[maxn];
int G[maxn][maxn];
bool fangwen[maxn];
/*
void initiate()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N;j++)
		{
			G[i][j].weight = 0;
			G[i][j].layer = 0;
		}
	}
}
*/

int bfs(int user)
{
	int ans = 0;
	queue<node> q;
	node usernode;
	usernode.user = user;
	usernode.layer = 0;
	q.push(usernode);
	fangwen[q.front().user] = 1;
	//int l = 0;
	while ( !q.empty())
	{
		//int curuser=q.front().user;
		//cout << curuser << " ";
		
		//q.pop();
		if (q.front().layer == L)
			break;
		for (int i = 1; i <= N; i++)
		{
			if (G[q.front().user][i] == 1 && fangwen[i]!=1)
			{
				fangwen[i] = 1;
				ans++;
				node curusernode;
				curusernode.user = i;
				curusernode.layer = q.front().layer + 1;
				q.push(curusernode);
			}
		}
		q.pop();
		//l++;
	}
	return ans;
}
int main()
{
	memset(G,0 ,sizeof(G) );
	//initiate();
	cin >> N >> L;
	for (int i = 1; i <= N; i++)
	{
		int userfollownumber, userfollow;
		cin >> userfollownumber;
		for (int j = 1; j <= userfollownumber; j++)
		{
			cin >> userfollow;
			G[userfollow][i] = 1;
		}
	}
	cin >> K;
	//for (int i = 0; i < K; i++)
		//cin >> k[i];
	for (int i = 0; i < K; i++)
	{
		cin >> k[i];
		memset(fangwen, 0, sizeof(fangwen));
		cout << bfs(k[i]) << endl;
	}
	return 0;
}
/*
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
*/
/*
//这么处理访问标记有问题
int bfs(int user)
{
int ans = 0;
queue<node> q;
node usernode;
usernode.user = user;
usernode.layer = 0;
q.push(usernode);
//int l = 0;
while ( !q.empty())
{
//int curuser=q.front().user;
//cout << curuser << " ";
fangwen[q.front().user]=1;
q.pop();
for (int i = 1; i <= N; i++)
{
if (G[q.front().user][i] == 1 && fangwen[i]!=1)
{
node curusernode;
curusernode.user = i;
curusernode.layer=q.front()
q.push(i);
}
}
q.pop();
//l++;
}
}

*/
