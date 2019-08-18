# @Time : 2019/6/26 16:19
# @Author : HXT
# @File : 3.2 两个数的和.py 
# @Software: PyCharm
# ======================================================================================================================
def get_ans(list, target):
    templist = list.copy()
    templist.sort()
    i = 0
    j = len(templist) - 1

    ansdict = {}
    while i <= j:
        if templist[i] + templist[j] == target:
            ansdict[templist[i]] = list.index(templist[i])
            ansdict[templist[j]] = list.index(templist[j])
            break
        elif templist[i] + templist[j] < target:
            i += 1
        else:
            j -= 1
    return ansdict


def get_ans_on(list, target):
    dict1 = {}
    for i in range(len(list)):
        if target - list[i] in dict1.keys():
            print("", list[i], dict1[target - list[i]])
            return
        else:
            dict1[list[i]] = i


if __name__ == "__main__":
    print("输入一个数，判断一个数列中是否有两个数的和是这个数")
    list1 = [3, 4, 5, 7, 10]
    target = int(input("Enter the target"))
    ansdict = get_ans(list1, target)
    print(ansdict)

    get_ans_on(list1, target)
