# @Time : 2019/6/29 11:18 
# @Author : HXT
# @File : 4.5 Maximum island.py
# @Software: PyCharm
# ======================================================================================================================


def load_data():
    return [[0, 0, 0, 0, 1, 1, 0],
            [0, 1, 1, 0, 1, 1, 0],
            [0, 1, 1, 0, 0, 1, 0],
            [0, 0, 1, 0, 0, 1, 1],
            [0, 0, 0, 0, 0, 0, 0],
            [0, 0, 1, 1, 0, 0, 0],
            [0, 0, 0, 1, 0, 0, 1]
            ]


# 判断当前点是否合理
def judge(Gmap, i, j):
    if i < 0 or i >= len(Gmap) or j < 0 or j >= len(Gmap[i]):
        return False
    if Gmap[i][j] == 2 or Gmap[i][j] == 0:
        return False
    return True


def dfs(Gmap, i, j, dir, curans):
    Gmap[i][j] = 2
    curans.append((i, j))

    for k in range(len(dir)):
        curi = i + dir[k][0]
        curj = j + dir[k][1]
        if judge(Gmap, curi, curj):
            dfs(Gmap, curi, curj, dir, curans)


# 主搜索函数
def search(Gmap, dir, ans):
    for i in range(len(Gmap)):
        for j in range(len(Gmap[i])):
            # Gmap[i][j]
            if Gmap[i][j] == 1:
                curans = []
                dfs(Gmap, i, j, dir, curans)
                if len(curans) > len(ans):
                    ans = curans
    print("ANS island sequence", ans)


if __name__ == "__main__":
    Gmap = []
    dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    Gmap = load_data()

    ans = []  # 最大岛屿的坐标组合
    curGmap = Gmap.copy()
    search(curGmap, dir, ans)
