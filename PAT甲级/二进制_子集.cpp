//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
void print_subset(int n, int s)//s表示集合的代号
{
	for (int i = 0; i<n; i++)
	{
		if ( s & (1 << i) )//(1<<i)遍历
			printf("%d", i);
		printf("\n");
	}
}
int main()
{
	int n = 4;
	1 << n;
	for (int i = 0; i< (1 << n); i++)
	{
		print_subset(n, i);//i表示集合的代号
	}
	return 0;
}

