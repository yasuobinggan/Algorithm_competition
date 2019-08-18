# @Time : 2019/5/6 20:14 
# @Author : Hxt
# @File : 2.2 二分查找.py 
# @Software: PyCharm

def BS(num, s, st, ed):
    mid = (st + ed) // 2
    # print(mid)
    if st > ed:
        return False, -1
    if num[mid] == s:
        return True, mid
    else:
        if num[mid] > s:
            return BS(num, s, st, mid - 1)
        else:
            return BS(num, s, mid + 1, ed)


def BS_it(num, s, st, ed):
    while (st <= ed):
        mid = (st + ed) // 2
        if num[mid] == s:
            return True, mid
        else:
            if num[mid] > s:
                ed = mid - 1
            else:
                st = mid + 1
    return False, -1


if __name__ == '__main__':
    num = [1, 3, 5, 6, 7, 8, 13, 14, 15, 17, 18, 24, 30, 43, 56]
    # print()
    s = int(input("Enter a number to search"))

    flag, pos = BS(num, s, 0, len(num) - 1)
    if flag == True:
        print("查找成功", pos)
    else:
        print("查找失败", pos)


    flag, pos = BS_it(num, s, 0, len(num) - 1)
    if flag == True:
        print("查找成功", pos)
    else:
        print("查找失败", pos)
