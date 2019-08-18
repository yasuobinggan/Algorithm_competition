# @Time : 2019/7/17 17:09 
# @Author : HXT
# @File : LLGoHome.py 
# @Software: PyCharm
# ======================================================================================================================
#
count = 0

# 分治
def solution1(N):
    global count

    if N == 1:
        count += 1
        return
    if N == 2:
        count += 2
        return
    else:
        solution1(N - 1)
        solution1(N - 2)


dp = []

# 动态规划(递归)
def solution2(N, dp):
    if N == 1 or N == 2:
        return dp[N]
    elif dp[N] != 0:
        return dp[N]
    else:
        dp[N] = solution2(N - 1, dp) + solution2(N - 2, dp)
        return dp[N]


# 动态规划(递推)
def solution3(N):
    for i in range(3, N + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[N]


if __name__ == "__main__":
    N = 10
    solution1(N)
    print("Number of solutions_1:", count)

    count = 0  # 主函数里修改全局变量不需要呀global
    # 初始化记录数组
    for i in range(10000):
        dp.append(0)
    dp[1], dp[2] = 1, 2
    count = solution2(N, dp)
    print("Number of solutions_2:", count)

    for i in range(10000):
        dp.append(0)
    dp[1], dp[2] = 1, 2
    count = solution3(N)
    print("Number of solutions_3:", count)
