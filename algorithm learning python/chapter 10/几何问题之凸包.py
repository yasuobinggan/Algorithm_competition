# @Time : 2019/7/4 11:07
# @Author : HXT
# @File : 几何问题之凸包.py
# @Software: PyCharm
# ======================================================================================================================
import sys
from math import sqrt

convexhullans = []


def data_load():
    N = int(input("Enter the amount of wspoints"))
    wspoints = []
    for i in range(N):
        a, b = input("Enter ith.x ith.y").split(" ")
        a, b = int(a), int(b)
        wspoints.append((a, b))
    return wspoints


def linear_get(point1, point2):
    if (point2[0] - point1[0]) != 0:
        k = (point2[1] - point1[1]) / (point2[0] - point1[0])
        c = point1[1] - k * point1[0]
        return [k, -1, c]
    else:
        return [1, 0, point1[0]]


def distance_get(point, linear_para):  #
    return point[0] * linear_para[0] + point[1] * linear_para[1] + linear_para[2]


def point_get(curpoints, leftpoint, rightpoint, flag):
    if len(curpoints) <= 0:  # len(curpoints)<=1
        return

    global convexhullans

    linea = linear_get(leftpoint, rightpoint)

    if flag == True:  # 求上包
        maxdistance = -sys.maxsize
        upchpoint = None
        uppoints = []
        for point in curpoints:
            curdistance = distance_get(point, linea)
            if curdistance > 0:
                uppoints.append(point)
                if curdistance > maxdistance:
                    upchpoint = point
                    maxdistance = curdistance
        if upchpoint != None:# 理解程序的关键
            convexhullans.append(upchpoint)

        point_get(uppoints, leftpoint, upchpoint, True)
        point_get(uppoints, upchpoint, rightpoint, True)

    else:
        mindistance = sys.maxsize
        downchpoint = None
        downpoints = []
        for point in curpoints:
            curdistance = distance_get(point, linea)
            if curdistance < 0:
                downpoints.append(point)
                if curdistance < mindistance:
                    downchpoint = point
                    mindistance = curdistance
        if downchpoint != None:# 理解程序的关键
            convexhullans.append(downchpoint)

        point_get(downpoints, leftpoint, downchpoint, False)
        point_get(downpoints, downchpoint, rightpoint, False)


def convexhull_get(wspoints):
    global convexhullans
    if len(wspoints) <= 3:  # 直接构成凸包
        convexhullans = wspoints
        return convexhullans
    else:
        wspoints.sort(key=lambda x: x[0])
        leftmostpoint = wspoints[0]
        rightmostpoint = wspoints[len(wspoints) - 1]
        convexhullans.append(leftmostpoint)
        convexhullans.append(rightmostpoint)
        point_get(wspoints, leftmostpoint, rightmostpoint, True)
        point_get(wspoints, leftmostpoint, rightmostpoint, False)

        return convexhullans


if __name__ == "__main__":
    # 0 0
    # 0 4
    # -4 0
    # 5 0
    # 0 -6
    # 1 0
    # -1 1
    # 3 3
    # 3 -5
    wspoints = data_load()  # ws 表示待选
    # 使用提前判断
    convexhullans = convexhull_get(wspoints)
    print(convexhullans)
