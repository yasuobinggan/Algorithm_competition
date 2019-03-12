/* CCF201612-4 压缩编码 */

#include <iostream>
#include <cstring>

using namespace std;

const int INT_MAX2 = 0x7F7F7F7F;
const int N = 1000;

int v[N+1];
int sum[N+1];
int dp[N+1][N+1];

int solve(int l, int r)
{
    if(dp[l][r] == INT_MAX2)
        for(int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + sum[r] - sum[l-1]);

    return dp[l][r];
}

int main()
{
    int n;

    // 变量初始化：置为最大值
    memset(dp, INT_MAX2, sizeof(dp));

    // 输入数据
    cin >> n;
    sum[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> v[i];

        sum[i] = sum[i-1] + v[i];
        dp[i][i] = 0;
    }

    // DP计算
    solve(1, n);

    // 输出结果
    cout << dp[1][n] << endl;

    return 0;
}
