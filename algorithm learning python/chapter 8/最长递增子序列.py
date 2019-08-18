# @Time : 2019/7/19 17:52 
# @Author : HXT
# @File : 最长递增子序列.py 
# @Software: PyCharm
# ======================================================================================================================
# 序列不连续

# 分治(选与不选)->动态规划
def solution1(inputlist):
    pass


# 动态规划O(n^2)
def getdp1(arr):
    # 初始化dp数组
    n = len(arr)
    dp = [0] * n  # 重复相同的元素
    # 对dp表填充
    for i in range(n):
        dp[i] = 1  # 关键
        for j in range(i):
            if arr[i] > arr[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    return dp


# 动态规划O(n*logn)
def getdp2(arr):
    n = len(arr)
    # 动态规划数组存标记
    dp = [0] * n
    dp[0] = 1
    # 结果数组存结果
    ends = [0] * n
    ends[0] = arr[0]
    # 二分查找使用
    right, l, r, m = 0, 0, 0, 0
    # 外部查找
    for i in range(1, n):
        l = 0
        r = n-1
        # 对当前数据进行二分查找
        while l <= r:
            m = (l + r) // 2
            if arr[i] < ends[m]:
                r = m - 1
            else:
                l = m + 1
        # right = max(right, l)#
        if l == n:
            ends.append(arr[i])
        else:
            ends[l] = arr[i]
        dp[i] = l + 1
    print(ends)
    return dp

# 根据dp数组生成最长递增子序列
def generaterLIS(arr, dp):
    n = max(dp)  # 数组最大值
    index = dp.index(n)  # 最大值下标
    # 建立生成的结果序列
    lis = [0] * n
    n -= 1  # 定位到新数组最后一个元素
    # 初始化结果序列
    lis[n] = arr[index]
    # 从右向左构建序列
    for i in range(index, -1, -1):
        if arr[i] < arr[index] and dp[i] == dp[index] - 1:
            n -= 1
            lis[n] = arr[i]
            index = i
    # 反回结果
    return lis


#
if __name__ == "__main__":
    inputlist = [3, 1, 4, 5, 9, 2, 6, 5, 0]

    dp = getdp1(inputlist)
    print(dp)
    result = generaterLIS(inputlist, dp)
    print(result)

    dp2 = getdp2(inputlist)
    print(dp2)
    # result2 = generaterLIS(inputlist, dp2)
    # print(result2)
