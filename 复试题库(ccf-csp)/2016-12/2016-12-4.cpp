#include<bits/stdc++.h>
using namespace std;
const int INF=0x7F7F7F7F;
const int N=1000;

int v[N+1];
int sum[N+1];
int dp[N+1][N+1];
//st为起始点,ed为结尾
int solve(int st,int ed)
{
    if(dp[st][ed]==INF)
    {
        for(int i=st;i<ed;i++)//i为分割点
            dp[st][ed]=min(dp[st][ed],solve(st,i)+solve(i+1,ed)+sum[ed]-sum[st-1]);
    }
    return dp[st][ed];
}

int main()
{
    int n;
    //初始化数据
    memset(dp,INF,sizeof(dp));
    //输入数据
    cin>>n;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        //前缀和
        sum[i]=sum[i-1]+v[i];
        //边界
        dp[i][i]=0;
    }
    //DP计算(顶为入口)
    solve(1,n);
    //输出结果
    cout<<dp[1][n]<<endl;

    return 0;
}
/*
5
1 3 4 2 5
*/
