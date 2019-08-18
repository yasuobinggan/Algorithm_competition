# @Time : 2019/5/6 16:08 
# @Author : Hxt
# @File : 2.1 有序数组合并.py
# @Software: PyCharm

arr1 = [1, 3, 4, 6, 10]
arr2 = [2, 5, 8, 11]
tarr = []


def merge1(arr1, arr2):
    i = 0
    j = 0
    k = 0

    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            tarr.append(arr1[i])
            i += 1
        elif arr1[i] > arr2[j]:
            tarr.append(arr2[j])
            j += 1
        else:
            tarr.append(arr1[i])
            i += 1
            j += 1
    while i < len(arr1):
        tarr.append(arr1[i])
        i += 1
    while j < len(arr2):
        tarr.append(arr2[j])
        j += 1


def merge2(arr1, arr2):
    ans = arr1.copy()
    st = 0
    for i in range(len(arr2)):
        for j in range(st, len(ans)):
            if arr2[i] < ans[j]:
                # print("!:")
                print(arr2[i])
                ans.insert(j, arr2[i])
                print(ans)
                st = j
                break
        else:
            ans += arr2[i:]
    return ans


if __name__ == '__main__':
    arr1.sort()
    arr2.sort()
    print(arr1)
    print(arr2)

    # merge1(arr1, arr2)
    ans = merge2(arr1, arr2)
    print(ans)

    # print(arr1)
    # print(arr2)
    print(tarr)
