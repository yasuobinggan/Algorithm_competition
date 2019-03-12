//更改成vector应该会更好
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxl = 26;
int G[maxl][maxl];//电话表//无向图

bool fang[maxl];
int gang_num[maxl];//每个团体的成员数
bool g_k_h[maxl];//是否大于阈值,是否是头的表

int K, N;
void dfs(int root, int i, int curwei, int &mtw, int &mti)//思考如何在合并中获得mtw或引用传参(直观上引用传参更好使用)//mtw,mti
{
    int stw=0;
	for(int j=0;j<maxl;j++)
    {
        stw+=G[i][j];

    }
    if(stw>mtw)
    {
        mtw=stw;
        mti=i;
    }
	if (curwei>K)
	{
		g_k_h[root] = true;
	}
	gang_num[root]++;

	for (int j = 0; j<maxl; j++)
	{
		if (G[i][j] != 0&&!fang[i])
		{
			fang[j]=true;
			curwei+=G[i][j];
			dfs(root, j, curwei, mtw, mti);
		}
	}

}
int main()
{
	char name1[3], name2[3];
	int weight;
	cin >> N >> K;

	memset(G, 0, sizeof(G));
	for (int i = 0; i<3; i++)
	{
		cin >> name1 >> name2;
		cin >> weight;
		G[name1[0] - 'A'][name2[0] - 'A'] += weight;
		G[name2[0] - 'A'][name1[0] - 'A'] += weight;
	}

	fill(gang_num, gang_num + maxl, 0);
	fill(g_k_h, g_k_h + maxl, 0);

	for (int i = 0; i<maxl; i++)
	{
		fill(fang, fang + maxl, 0);
		dfs(i, i, 0, 0, i);
	}


	int ans = 0;
	for (int i = 0; i<maxl; i++)
	{
		ans += g_k_h[i];
	}
	cout << ans << endl;
	for (int i = 0; i<maxl; i++)
	{
		if (g_k_h[i])
		{
			cout << (i + 'A') * 3 << " " << gang_num[i] << endl;
		}
	}
	return 0;
}
