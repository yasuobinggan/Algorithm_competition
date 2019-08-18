# @Time : 2019/7/4 9:17
# @Author : HXT
# @File : 斐波那契数列.py
# @Software: PyCharm
# ======================================================================================================================
###重要的动态规划文件
# 动态规划思想解决斐波那契数列
MAXN = 10000


def init(dp):
    # dp = [0 for i in range(MAXN)]
    for i in range(MAXN):
        dp.append(0)

def F(n, dp):
    if n == 1 or n == 2:
        return 1
    # 两种情况记忆过与没记忆过
    if dp[n] != 0:
        return dp[n]
    else:  # 返回前记忆,返回记忆的值
        dp[n] = F(n - 1, dp) + F(n - 2, dp)# 返回前直接记忆
        return dp[n]


if __name__ == "__main__":
    dp = []
    init(dp)
    n = int(input("Enter the i-th item of list:"))
    print(F(n, dp))
