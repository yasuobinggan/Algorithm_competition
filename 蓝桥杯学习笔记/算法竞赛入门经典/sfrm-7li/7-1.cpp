#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;
bool check(int m, int n)
{
	bool ok = true;
	int vis[10];//十个位置的数字表 
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < 5; i++)
	{
		vis[m % 10]++, vis[n % 10]++;
		if (vis[m % 10]>1 || vis[n % 10] > 1)//表的情况反应重复 
			ok = false;
		m /= 10, n /= 10;
	}
	return ok;
}
int main()
{
	//freopen("t.txt", "r", stdin);
	int n;
	int rnd = 0;
	while (~scanf("%d", &n) && n)
	{
		if (rnd++)
			cout << endl;
		int ok = 0;
		for (int divisor = 1234; divisor <= 100000/n; divisor++)
		{
			int m = divisor*n;
			if (check(m, divisor))
			{
				ok = 1;
				printf("%05d / %05d = %d\n", m, divisor, n);//输出技巧 
			}
		}
		if (!ok)
			printf("There are no solutions for %d.\n", n);
	}
	return 0;
}
