# @Time : 2019/5/10 16:57
# @Author : Hxt
# @File : 2.3 单链表.py
# @Software: PyCharm

# 第一种链表实现方法

ListValue = [1, 5, 6, 2, 4, 3]
ListPointer = [3, 2, -1, 5, 1, 4]

# 先输出链首元素，再循环输出剩余元素
# head = 0
# print(ListValue[head])
# next=ListPointer[head]
#
# while next != -1:
#     print(ListValue[next])
#     next=ListPointer[next]

next = 0
while next != -1:
    print(ListValue[next])
    next = ListPointer[next]

LinkedList = [[1, 3], [5, 2], [6, -1], [2, 5], [4, 1], [3, 4]]

value = 0
next = 1
next = 0
while next != -1:
    print(LinkedList[next][0])
    next = LinkedList[next][1]
