# @Time : 2019/7/3 14:50 
# @Author : HXT
# @File : 归并排序.py 
# @Software: PyCharm
# ======================================================================================================================
# 递归法(Top-down)
# 迭代法(Bottom-up)

# 使用迭代法实现

def merge_sort(list):
    n = 1
    while n < len(list):  # n控制合并的步长
        for i in range(0, len(list), n*2):

            A = list[i:i + n]  # slice 切片
            B = list[i + n:i + n*2]

            Ai, Bi = 0, 0
            Li = i
            while Ai < len(A) and Bi < len(B):
                if A[Ai] <= B[Bi]:
                    list[Li] = A[Ai]
                    Ai += 1
                else:
                    list[Li] = B[Bi]
                    Bi += 1
                Li += 1
            if Ai < len(A):
                list[Li:i + n*2] = A[Ai:]
            elif Bi < len(B):
                list[Li:i + n*2] = B[Bi:]
            # while Ai<len(A):
            #     list[Li]=A[Ai]
            #     Ai+=1
            #     Li+=1
            # while Bi<len(B):
            #     list[Li]=B[Bi]
            #     Bi+=1
            #     Li+=1

        n *= 2


if __name__ == "__main__":
    inputlist = list(input("Enter a list").split(" "))
    for i in range(len(inputlist)):
        inputlist[i] = int(inputlist[i])  # 强制将字符串改写成int类型
    merge_sort(inputlist)
    print(inputlist)
