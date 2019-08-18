# @Time : 2019/6/26 15:40 
# @Author : HXT
# @File : merge sort.py 
# @Software: PyCharm
# =======================================================================================================================
def merge(list, st, mid, ed):
    anslist = []
    list1 = list[st:mid + 1]
    list2 = list[mid + 1:ed + 1]

    i, j = 0, 0
    while i < len(list1) and j < len(list2):
        if list1[i] <= list2[j]:
            anslist.append(list1[i])
            i += 1
        else:
            anslist.append(list2[j])
            j += 1
    if i < len(list1):
        anslist.extend(list1[i:])
    else:
        anslist.extend(list2[j:])

    for k in range(len(anslist)):
        list[st + k] = anslist[k]
    # return anslist


def merge_sort(list1, st, ed):
    if st >= ed:
        return
    else:
        mid = (st + ed) // 2
        merge_sort(list1, st, mid)
        merge_sort(list1, mid + 1, ed)
        merge(list1, st, mid, ed)


if __name__ == "__main__":
    # list1 = []
    # N = int(input("Enter the amount of numbers"))
    # for i in range(N):
    #     list1.append(int(input("Enter number")))

    list1 = [2, 3, 6, 4, 1, 7, 8, 5, 9, 10]
    print(list1)
    st = 0
    ed = len(list1) - 1
    print("sorting")
    merge_sort(list1, st, ed)
    print("sorted\n", list1)
