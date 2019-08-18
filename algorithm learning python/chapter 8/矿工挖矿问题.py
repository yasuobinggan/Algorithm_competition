# @Time : 2019/7/17 20:06 
# @Author : HXT
# @File : 矿工挖矿问题.py 
# @Software: PyCharm
# ======================================================================================================================
# 列表也能承担标记的能力
import sys, os

"""
1 400 5
2 500 5
3 200 3
4 300 4
5 350 3
"""

maxweight = -sys.maxsize
ansminelist = []


# 分治
def solution1(minelist, index, sumnumber, cursumnumber, curminelist, curweight):
    if index == len(minelist):
        return

    global maxweight, ansminelist
    if cursumnumber + minelist[index][1] <= sumnumber:
        cursumnumber += minelist[index][1]
        curweight += minelist[index][0]
        curminelist.append(minelist[index])

        if curweight > maxweight:
            maxweight = curweight
            ansminelist = curminelist.copy()

        # for i in range(index, len(minelist)):
        solution1(minelist, index + 1, sumnumber, cursumnumber, curminelist, curweight)

        cursumnumber -= minelist[index][1]
        curweight -= minelist[index][0]
        curminelist.remove(minelist[index])

        # for i in range(index, len(minelist)):
        solution1(minelist, index + 1, sumnumber, cursumnumber, curminelist, curweight)


# 动态规划
def solution2(n, w, g, p):
    preresult, result = [], []
    # 填充列表的第一位
    preresult.append(0)
    result.append(0)

    # 初始化边界
    for i in range(1, w + 1):
        if i < p[0]:
            preresult.append(0)
        else:
            preresult.append(g[0])
        result.append(0)  # 填充结果数组
    # 填表
    for ni in range(1, n):
        for i in range(1, w + 1):
            if i < p[ni]:# 事先的填充已经让坐标对齐
                result[i] = preresult[i]
            else:
                result[i] = max(preresult[i], preresult[i - p[ni]] + g[ni])
        preresult = result.copy()# 传递给下一行表
    return result[1:]


if __name__ == "__main__":
    # N = int(input("Enter the amount of mine"))
    # minelist = []
    # minnumber = sys.maxsize
    # for i in range(N):
    #     weight = int(input("Enter the weight"))
    #     number = int(input("Enter the number"))
    #     minnumber = min(minnumber, number)
    #     curpair = (weight, number)
    #     minelist.append(curpair)
    # sumnumber = int(input("Enter the sumnumber"))
    #
    # curminelist = []
    # solution1(minelist, 0, sumnumber, 0, curminelist, 0)
    # print(ansminelist, ":", maxweight)

    n = 5
    w = 10
    g = [400, 500, 200, 300, 350]
    p = [5, 5, 3, 4, 3]
    result = solution2(n, w, g, p)
    print(result)
