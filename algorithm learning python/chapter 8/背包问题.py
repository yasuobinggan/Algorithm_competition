# @Time : 2019/7/18 21:50 
# @Author : HXT
# @File : 背包问题.py 
# @Software: PyCharm
# ======================================================================================================================
# 背包问题的思考


# 动态规划(根据上一行更新)
def solution1(n, sumw, v, w):
    preresult, result = [], []
    # 填充列表的第一位
    preresult.append(0)
    result.append(0)

    # 初始化边界
    for i in range(1, sumw + 1):
        if i < w[0]:
            preresult.append(0)
        else:
            preresult.append(v[0])
        result.append(0)  # 填充结果数组
    # 填表
    for ni in range(1, n):
        for i in range(1, sumw + 1):
            if i < w[ni]:
                result[i] = preresult[i]
            else:
                result[i] = max(preresult[i], preresult[i - w[ni]] + v[ni])
        preresult = result.copy()  # 传递给下一行表
    return result[1:]


# 动态规划(利用表填充)
def solution2(n, sumw, v, w):
    # 初始化边界()
    resulttable = [[0 for i in range(sumw + 1)] for i in range(n + 1)]
    # 对表进行填充
    for i in range(1, n + 1):
        for j in range(1, sumw + 1):
            if j < w[i - 1]:
                resulttable[i][j] = resulttable[i - 1][j]
            else:
                resulttable[i][j] = max(resulttable[i - 1][j], resulttable[i - 1][j - w[i - 1]] + v[i - 1])
    print(resulttable)
    return resulttable


# 通过回溯选择最优的解并输出
def recall_show(n, sumw, v, w, resulttable):
    pass
    visited = [0 for i in range(sumw + 1)]
    i, j = n, sumw
    while i >= 0:
        if resulttable[i][j] > resulttable[i - 1][j]:
            visited[i] = True
            j -= w[i - 1]
        i -= 1
    # 输出
    print("CHOOSE:")
    for i in range(n):
        if visited[i] == True:
            print(i, " ", end="")
    print("\n")


if __name__ == "__main__":
    n = 4  # 物品数量
    sumw = 9  # 总重量
    v = [5, 4, 6, 2]
    w = [2, 4, 5, 3]

    result = solution1(n, sumw, v, w)
    print(result)

    resulttable = solution2(n, sumw, v, w)
    print(resulttable[n][sumw])  # 输出最大结果
    # 回溯
    recall_show(n, sumw, v, w, resulttable)
