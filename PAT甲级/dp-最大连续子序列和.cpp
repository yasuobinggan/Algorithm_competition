#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int A[maxn],dp[maxn];
int main()
{
    int n;
    //输入
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    //初始化边界
    dp[0]=A[0];
    //动态规划求解
    int k=0;
    for(int i=1;i<n;i++)
    {
        //状态转移方程
        dp[i]=max(A[i],dp[i-1]+A[i]);
        //找最大解
        if(dp[i]>dp[k])
        {
            k=i;
        }
    }

    printf("%d\n",dp[k]);
    return 0;
}
/*
6
-2 11 -4 13 -5 -2
*/
