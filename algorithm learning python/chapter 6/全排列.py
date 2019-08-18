# @Time : 2019/7/6 15:35 
# @Author : HXT
# @File : 全排列.py 
# @Software: PyCharm
# ======================================================================================================================
count = 0

# 以选择的方式生成全排列
def solution1(list, anslist):
    global count
    if len(anslist) == len(list):
        print(anslist)
        count += 1
        return
    else:
        for i in range(len(list)):
            if list[i] not in anslist:  # 操作的序列无重复元素 # 有重复元素的数列可以考虑开哈希列表处理
                anslist.append(list[i])
                solution1(list, anslist)
                anslist.remove(list[i])


def swap(a, b):
    return b, a

# 以交换的方式生成全排列
def solution2(list, curindex):
    global count
    if curindex == len(list) - 1:
        print(list)
        count += 1
        return
    else:
        for i in range(curindex, len(list)):
            list[i], list[curindex] = swap(list[i], list[curindex])
            solution2(list, curindex + 1)
            list[i], list[curindex] = swap(list[i], list[curindex])


if __name__ == "__main__":
    inputlist = input("Enter the list").split(" ")

    anslist = []
    #
    solution1(inputlist, anslist)
    print("*******************************")
    solution2(inputlist, 0)

    print(count)
