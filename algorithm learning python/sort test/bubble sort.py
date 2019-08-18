# @Time : 2019/6/26 15:26 
# @Author : HXT
# @File : bubble sort.py 
# @Software: PyCharm
# =======================================================================================================================

def bubble_sort(list1, st, ed):
    for i in range(ed):
        for j in range(0, ed - i):
            if list1[j] > list1[j + 1]:
                list1[j + 1], list1[j] = list1[j], list1[j + 1]


if __name__ == "__main__":
    list1 = []
    N = int(input("Enter the amount of numbers"))
    for i in range(N):
        list1.append(int(input("Enter number")))
    print(list1)
    st = 0
    ed = len(list1) - 1
    print("sorting")
    bubble_sort(list1, st, ed)
    print("sorted", list1)
