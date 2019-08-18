# @Time : 2019/6/30 20:59 
# @Author : HXT
# @File : The wisdom of choosing courses.py 
# @Software: PyCharm
# ======================================================================================================================
from collections import deque


def load_data():
    return [
        [0, 0, 1, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 0, 1],
        [0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0]
    ]


# 拓扑排序（用列表模拟队列）（导入deque）
def topo(Gmap):  # Gmap n * n 矩阵
    # 建立先序数组
    prelist = [0] * len(Gmap)
    for j in range(len(Gmap)):
        for i in range(len(Gmap)):
            prelist[j] += Gmap[i][j]
    # 建立队列
    topo = deque()
    for i in range(len(prelist)):
        if prelist[i] == 0:
            topo.append(i)

    ans = []
    while len(topo) > 0:
        curnode = topo.popleft()
        ans.append(curnode)
        for j in range(len(Gmap[curnode])):
            if Gmap[curnode][j] == 1:
                prelist[j] -= 1
                if prelist[j] == 0:
                    topo.append(j)

    if len(ans) != len(Gmap):
        print("Topo False")
    else:
        print("ANS Topo",ans)

if __name__ == "__main__":
    Gmap = load_data()
    # print(Gmap)
    topo(Gmap)
