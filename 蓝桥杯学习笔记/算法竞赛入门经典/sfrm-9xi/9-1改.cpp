//记忆化搜索建立在最优化子结构上
 
#include<bits/stdc++.h>
using namespace std;
#define M 105
#define N 4
int dir[4][2]={
	0,1,
	0,-1,
	1,0,
	-1,0,
};
int G[M][N];
int dp[M][N];
char name[N*10];//不懂
int r,c;
//int ans=0;

int DP(int x,int y)
{
	int &cnt=dp[x][y];
	if(cnt!=-1)
		return cnt;
//	if(cnt==-1)//更改dp数组的值 
//		cnt=1;
	for(int i=0;i<M;i++)
	{
		int newx=x+dir[i][0];
		int newy=y+dir[i][1];
		if(newx>=0&&newx<r&&newy>=0&&newy<c)
		{
			if(G[x][y]>G[newx][newy])
				cnt=max(cnt,DP(newx,newy)+1);//更改dp数组的值
		}
	}
	if(cnt==-1)//更改dp数组的值 
		cnt=1;
	return cnt;
 } 
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
			cin>>G[i][j];
	 } 
	 
	 memset(dp,-1,sizeof(dp));
	 int ans=-1;
	 
	 for(int i=0;i<r;i++)
	 {
	 	for(int j=0;j<c;j++)
	 		ans=max(ans,DP(i,j));
	 }
	 cout<<ans<<endl; 
	return 0;
}

