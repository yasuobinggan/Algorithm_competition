# @Time : 2019/6/25 17:19
# @Author : Hxt
# @File : test.py
# @Software: PyCharm
# =======================================================================================================================

import collections
import numpy as np
import pandas as pd

'''
列表与元组
'''
# a = int(input("Enter a number"))
# print("H %s T" % (a))
#
# list1 = [18, 8, 7, 2, 3, 6, 1, 11]
# print(list1.index(8, 1, 2))
# listnew = sorted(list1, reverse=False)
# print(listnew)
# # list1.sort(reverse=True)
# print("H", list1, "X")

# tuple1 = (1,2,56,6,7,4,5)
# # print(type(tuple1))
#
# # print(tuple1.index([6,7]))
# print(sum(tuple1))

'''
字典
'''
# print(int("45646"))
#
# dict1 = {1: "H", 2: "X", 2: "T"}
# # print(dict1)
# # dict1.setdefault(3,"T")
# # print(dict1)
# #
# # print({1:"H"} in dict1.items())
# # dict2={1:"Z",56:"Y",}
# dict2 = {}
# for i in range(26):
#     dict2[i + 1] = chr(ord("a") + i)
#
# dict1.update(dict2)
# print(dict1)
#
# dict1.popitem()
#
# popvalue = dict1.pop(15, "o")
# print(popvalue)
#
# # i = 0
# for i in range(0, 10):
#     if i == 4:
#         break
# print(i)
#
# dNone={}.fromkeys(["H","X","T"])
# for dNoneitem in dNone.values():
#     print(type(dNoneitem))
#
#
# print(type(range(10)))

# dict1={1:"H",2:"X"}
# dict2={}
# dict2=dict1.copy()
#
# print(dict2)

'''
集合
'''
# seta=set((12,45,789,5,'a',"fdf"))
# print(seta)

# strinput=input("Enter").split("")
# print(strinput)

'''
对实例的修改部分
'''
# class node():
#     def __init__(self, a, b, c, d):
#         self.a = a
#         self.b = b
#         self.c = c
#         self.HXT = d
#
# child = node(11,22,33,None)
# n = node(1, 2, 3, child)
#
# def change(n, x, y, z):
#
#     print("修改前", n.a, n.b, n.c, n.HXT.a, n.HXT.b, n.HXT.c)
#
#     childfun = node(44, 55, 66, None)
#     n.a,n.b,n.c = x,y,z
#     n.HXT = childfun
#
#
#     print("函数内修改完", n.a, n.b, n.c, n.HXT.a, n.HXT.b, n.HXT.c)
#
# change(n,4,5,6)

# print("函数外修改完", n.a, n.b, n.c, n.HXT.a, n.HXT.b, n.HXT.c)

'''

'''
#
# list1 = [3,2,4]
# print(max(list1))

# print(True)

# if True == 1:
# print("I Love Nakashima Mika")

# print(True and False and True)

# list1 = [3,4,5,6,7,8,9,10]
# print(list1[-1])

# a = collections.defaultdict(list)
#
# print(a)
# a[1]=["H","X","T"]
# a[2]=2
# print(a)

# a = set([1, 2, 3])
# b = set([1, 2, 3, 4, 5, 6])
#
# ans = b - a
# print(ans)

# a = [[1, 1, 1],
#      [1, 1, 1],
#      [1, 1, 1]]
# b = [[1, 1, 1],
#      [1, 1, 1],
#      [1, 1, 1]]
# a = np.array(a)
# b = np.array(b)
# print(a * b)
# print(np.dot(a, b))

a = ["H","X","T"]
b = ["H","X","T"]
if a == b:
    print(True)
    print(id(a))
    print(id(b))