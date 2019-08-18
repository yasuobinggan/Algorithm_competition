# @Time : 2019/7/2 12:27 
# @Author : HXT
# @File : 9.2 Floyd.py 
# @Software: PyCharm
# ======================================================================================================================
import sys


class Solution():
    def __init__(self):
        pass

    def path_construct(self, N):
        path = []
        for i in range(N):
            row = []
            for j in range(N):
                row.append(j)
            path.append(row)
        return path

    def path_print(self, path, st, ed):
        cur = st
        print(cur, "\t", end="")
        while path[cur][ed] != ed:
            print(path[cur][ed], "\t", end="")
            cur = path[cur][ed]
        print(path[cur][ed])

    def Floyd(self, Gmap):
        path = self.path_construct(len(Gmap))
        # test
        # self.test(path)

        # get mindistances
        for k in range(len(Gmap)):
            for i in range(len(Gmap)):
                for j in range(len(Gmap[i])):
                    if Gmap[i][k] + Gmap[k][j] < Gmap[i][j]:
                        Gmap[i][j] = Gmap[i][k] + Gmap[k][j]
                        path[i][j] = path[i][k]

        for i in range(len(Gmap)):
            for j in range(len(Gmap[i])):
                print("PATH:", i, "=>", j)
                self.path_print(path, i, j)
        # test
        # self.test(path)

    def test(self, G):
        for i in range(len(G)):
            for j in range(len(G[i])):
                print(G[i][j], "\t", end="")  # end="" 控制输出在一行
            print("\n")


Solution().Floyd([[0, 10, 15, sys.maxsize, 30, sys.maxsize],
                  [10, 0, sys.maxsize, 5, 14, sys.maxsize],
                  [15, sys.maxsize, 0, 12, 12, sys.maxsize],
                  [sys.maxsize, 5, 12, 0, sys.maxsize, 10],
                  [30, 14, 12, sys.maxsize, 0, 20],
                  [sys.maxsize, sys.maxsize, sys.maxsize, 10, 20, 0]])
# Solution().test()
