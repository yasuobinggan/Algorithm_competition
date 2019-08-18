# @Time : 2019/7/1 16:01
# @Author : HXT
# @File : Look for the Hight ground - dfs.py
# @Software: PyCharm
# ======================================================================================================================
import time

dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]


def load_data():
    return [[1, 3, 2, 3, 5],
            [3, 4, 5, 6, 3],
            [2, 7, 4, 3, 3],
            [5, 2, 2, 3, 1]]


def judge(Gmap, newi, newj, curi, curj, curset):
    if newi < 0 or newi >= len(Gmap) or newj < 0 or newj >= len(Gmap[0]):
        return False
    if Gmap[newi][newj] > Gmap[curi][curj]:
        return False
    if (newi, newj) in curset:
        return False
    return True


def dfs(Gmap, i, j, curset):
    topflag, bottomflag, leftflag, rightflag = False, False, False, False
    if i == 0:
        topflag = True
    if i == len(Gmap) - 1:
        bottomflag = True
    if j == 0:
        leftflag = True
    if j == len(Gmap[0]) - 1:
        rightflag = True
    curset.add((i, j))

    for k in dir:
        newi = i + k[0]
        newj = j + k[1]
        if judge(Gmap, newi, newj, i, j, curset):
            a, b, c, d = dfs(Gmap, newi, newj, curset)
            topflag = topflag or a
            bottomflag = bottomflag or b
            leftflag = leftflag or c
            rightflag = rightflag or d

    return topflag, bottomflag, leftflag, rightflag


def search(Gmap):
    ans = []
    m = len(Gmap)
    n = len(Gmap[0])

    for i in range(m):
        for j in range(n):
            curset = set()
            # topflag, bottomflag, leftflag, rightflag = False, False, False, False
            a, b, c, d = dfs(Gmap, i, j, curset)
            if a and b and c and d:
                ans.append((i, j))

    print(ans)
    return ans


if __name__ == "__main__":
    Gmap = load_data()
    search(Gmap)
    print("DFS运行时间(s):", time.clock())
