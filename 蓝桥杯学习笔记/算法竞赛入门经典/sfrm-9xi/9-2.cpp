/*
	记忆化搜索 
*/ 
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>

using namespace std;
#define MAXN 41
int pile[4][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int n,top[4];//top标记每个堆的出栈位置 
int dfs(int count,bool hash[])
{
	if(dp[top[0]][top[1]][top[2]][top[3]]!=-1)
		return dp[top[0]][top[1]][top[2]][top[3]];
		
	if(count==5)
		return dp[top[0]][top[1]][top[2]][top[3]]=0;
	
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(top[i]==n)//这个堆已经取到底 
			continue;
		int color=pile[i][top[i]];
		++top[i];
		if(hash[color])//颜色匹配 
		{
			//
			hash[color]=false;
			ans=max(ans,dfs(count-1,hash)+1);
			hash[color]=true;
		}
		else//颜色不匹配 
		{
			//
			hash[color]=true;
			ans=max(ans,dfs(count+1,hash));
			hash[color]=false;
		}
		--top[i];
	}
	
	return dp[top[0]][top[1]][top[2]][top[3]]=ans;
 } 
int main()
{
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<4;j++)
				cin>>pile[i][j];
		}
		
		bool hash[25];//颜色的标记位 
		memset(dp,-1,sizeof(dp));
		memset(hash,false,sizeof(hash));
		top[0]=top[1]=top[2]=top[3]=0;
		cout<<dfs(0,hash);
	}
	return 0;
 } 
