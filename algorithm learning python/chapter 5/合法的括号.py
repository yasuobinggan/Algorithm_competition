
# @Time : 2019/7/1 20:26
# @Author : HXT
# @File : 合法的括号.py
# @Software: PyCharm
# ======================================================================================================================

def judge(curstr):
    count = 0
    for curchar in curstr:
        if curchar == "(":
            count += 1
        elif curchar == ")":
            count -= 1
        if count < 0:
            return False
    return True


# 第一个最长合法串
def MY_bfs(str):
    ans = []
    queue = []
    strset = set()
    queue.append(str)
    strset.add(str)

    while len(queue) > 0:
        curstr = queue.pop(0)
        if judge(curstr):
            print(curstr)
            return
        for i in range(len(curstr)):
            if curstr[i] == "(" or curstr[i] == ")":
                newstr = curstr[0:i] + curstr[i + 1:]
                if newstr not in strset:
                    queue.append(newstr)


def BOOK_bfs(str):
    ans = []

    queue = []
    queue.append(str)

    while len(queue) > 0:
        for i in range(len(queue)):
            if judge(queue[i]):
                ans.append(queue[i])
        if len(ans) > 0:
            print(set(ans))  # 可以不去重
            return
        # 以替换的方式实现出队入队
        temp = set()
        for i in range(len(queue)):
            for j in range(len(queue[i])):
                if queue[i][j] == "(" or queue[i][j] == ")":
                    newstr = queue[i][0:j] + queue[i][j + 1:]
                    temp.add(newstr)
        queue = list(temp)


if __name__ == "__main__":
    inputstr = input("Enter a string")
    MY_bfs(inputstr)
    BOOK_bfs(inputstr)