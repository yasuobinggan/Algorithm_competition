# @Time : 2019/7/8 17:47 
# @Author : HXT
# @File : 八皇后问题.py 
# @Software: PyCharm
# ======================================================================================================================
import os

import numpy as np

count = 0
res = [(0, 6), (1, 3), (2, 0), (3, 6), (4, 2), (5, 7), (6, 5), (7, 3)]

def load_data():
    data = []
    for i in range(8):
        curdata = []
        for j in range(8):
            curdata.append(0)
        data.append(curdata)
    return data


def mark(Gmap, index, j, op, length):
    # 纵向标记
    for curindex in range(index, length):
        Gmap[curindex][j] += op
    # 主斜线
    curindex = index
    curj = j
    while curindex < length and curj < length:
        Gmap[curindex][curj] += op
        curindex += 1
        curj += 1
    # 副斜线
    curindex = index
    curj = j
    while curindex < length and curj >= 0:
        Gmap[curindex][curj] += op
        curindex += 1
        curj -= 1

# 回溯置空时可能导致过多的操作!!!
# 标记错误
def solution(Gmap, index, anslist, length):
    if index == length:
        print(anslist)
        global count
        count += 1
        return
    else:
        for j in range(length):
            if Gmap[index][j] == 0:
                anslist.append((index, j))
                mark(Gmap, index, j, 1, length)

                solution(Gmap, index + 1, anslist, length)

                mark(Gmap, index, j, -1, length)
                anslist.pop()
        # res = [(0, 6), (1, 3), (2, 0), (3, 6), (4, 2), (5, 7), (6, 5), (7, 3)]
        # if Gmap[res[index][0]][res[index][1]] == 0:
        #     anslist.append(res[index])
        #     mark(Gmap, index, res[index][1], 1, length)
        #
        #     solution(Gmap, index + 1, anslist, length)
        #
        #     mark(Gmap, index, res[index][1], 0, length)
        #     anslist.remove(res[index])


if __name__ == "__main__":
    data = load_data()
    # print(data)
    #
    # mark(data,0,0,1,8)
    # mark(data,1,5,2,8)
    # mark(data,2,7,3,8)
    # mark(data,3,2,4,8)
    # mark(data,4,6,5,8)
    # mark(data,5,3,6,8)
    # mark(data,6,1,7,8)
    # mark(data,7,4,8,8)
    # print("------------")
    # print(data)

    anslist = []

    solution(data, 0, anslist, len(data))
    print(count)# 92
