# @Time : 2019/6/30 22:43 
# @Author : HXT
# @File : Look for the Hight ground - bfs.py
# @Software: PyCharm
# ======================================================================================================================
# 尾缀是set的变量是图遍历中的标记数组
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
    if Gmap[newi][newj] < Gmap[curi][curj]:
        return False
    if (newi,newj) in curset:
        return False
    return True


def bfs(Gmap, curset):
    quence = list(curset)

    while len(quence) > 0:
        curnode = quence.pop(0)
        for k in range(len(dir)):
            newi = curnode[0] + dir[k][0]
            newj = curnode[1] + dir[k][1]
            if judge(Gmap, newi, newj, curnode[0], curnode[1], curset):
                quence.append((newi, newj))
                curset.add((newi, newj))


def search(Gmap):
    m = len(Gmap)
    n = len(Gmap[0])

    topset = set([(0, j) for j in range(n)])
    bfs(Gmap, topset)
    bottomset = set([(m - 1, j) for j in range(n)])
    bfs(Gmap, bottomset)
    leftset = set([(i, 0) for i in range(m)])
    bfs(Gmap, leftset)
    rightset = set([(i, n - 1) for i in range(m)])
    bfs(Gmap, rightset)

    ansset = topset & bottomset & leftset & rightset
    print(ansset)


if __name__ == "__main__":
    Gmap = load_data()
    search(Gmap)
    print("BFS运行时间(s):",time.clock())
