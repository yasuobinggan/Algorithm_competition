# @Time : 2019/7/4 9:04 
# @Author : HXT
# @File : 连续子列表的最大和.py 
# @Software: PyCharm
# ======================================================================================================================
import sys, time


def subarray_max_BOOK(list):
    # if len(list) == 0:  # 可以注释
    #     return 0
    if len(list) == 1:
        return list[0]
    else:
        cut = len(list) // 2
        leftlist = list[:cut]
        rightlist = list[cut:]
        leftsum = subarray_max_BOOK(leftlist)
        rightsum = subarray_max_BOOK(rightlist)

        leftmiddlesum, leftmax = 0, -sys.maxsize
        for i in range(len(leftlist) - 1, -1, -1):  # 注意左闭右开
            leftmiddlesum += leftlist[i]
            leftmax = max(leftmiddlesum, leftmax)
        rightmiddlesum, rightmax = 0, -sys.maxsize
        for i in range(0, len(rightlist), 1):  # 刨除cut点
            rightmiddlesum += rightlist[i]
            rightmax = max(rightmiddlesum, rightmax)

        return max(leftsum, rightsum, leftmax + rightmax)


def subarray_max_MY(list, st, ed):
    if len(list) == 0:  # 可以注释
        return 0
    if len(list) == 1:
        return list[0]
    else:
        cut = len(list) // 2

        leftmiddlesum, lefted, leftmax = 0, 0, -sys.maxsize
        for i in range(cut - 1, -1, -1):  # 注意左闭右开
            leftmiddlesum += list[i]
            if leftmiddlesum > leftmax:
                leftmax = leftmiddlesum
                lefted = i - 1

        rightmiddlesum, rightst, rightmax = 0, 0, -sys.maxsize
        for i in range(cut, len(list), 1):  # 刨除cut点
            rightmiddlesum += list[i]
            if rightmiddlesum > rightmax:
                rightmax = rightmiddlesum
                rightst = i + 1

        leftlist = list[st:lefted + 1]
        rightlist = list[rightst:ed + 1]
        leftsum = subarray_max_BOOK(leftlist)
        rightsum = subarray_max_BOOK(rightlist)

        return max(leftsum, rightsum, leftmax + rightmax)


if __name__ == "__main__":
    # -2 1 -3 4 -1 2 1 -5 4
    # inputlist = list(input("Enter a list").split(" "))
    # for i in range(len(inputlist)):
    #     inputlist[i] = int(inputlist[i])  # 强制将字符串改写成int类型
    inputlist = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    t1 = time.clock()
    for i in range(100000):
        print("BOOK:", subarray_max_BOOK(inputlist))
    t2 = time.clock()
    t3 = time.clock()
    for i in range(100000):
        print("MY:", subarray_max_MY(inputlist, 0, len(inputlist) - 1))
    t4 = time.clock()

    print(t2 - t1, t4 - t3)
