# @Time : 2019/6/26 10:50 
# @Author : HXT
# @File : quick sort.py 
# @Software: PyCharm
# =======================================================================================================================


def get_position(list1, st, ed):
    print(".")
    key = list1[st]
    i = st
    j = ed
    while i < j:
        while (list1[j] >= key and i < j):
            j -= 1
        list1[i], list1[j] = list1[j], list1[i]
        while (list1[i] <= key and i < j):
            i += 1
        list1[i], list1[j] = list1[j], list1[i]
    list1[i] = key
    return i


def MY_quick_sort(list1, st, ed):
    if st >= ed:
        return
    else:
        pos = get_position(list1, st, ed)
        MY_quick_sort(list1, st, pos - 1)
        MY_quick_sort(list1, pos + 1, ed)


if __name__ == "__main__":
    list1=[]
    N = int(input("Enter the amount of numbers"))
    for i in range(N):
        list1.append(int(input("Enter number")))
    print(list1)
    st = 0
    ed = len(list1) - 1
    print("sorting")
    MY_quick_sort(list1, st, ed)
    print("sorted", list1)
