# @Time : 2019/7/8 16:31 
# @Author : HXT
# @File : 单词查找问题.py 
# @Software: PyCharm
# ======================================================================================================================
# dir = [[1, 0], [-1, 0], [0, 1], [0, -1], [1, 1], [1, -1], [-1, 1], [-1, -1]]
dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]


def load_data():
    return [["a", "e", "r", "y", "l"],
            ["l", "w", "o", "r", "i"],
            ["a", "f", "d", "l", "e"],
            ["k", "e", "e", "w", "e"],
            ["o", "d", "r", "o", "s"]]

# 采用提前判断更好
# 当前判断
def search(i, j, board, tarword, index, curset):
    if index == len(tarword):# 当前判断会造成最后一步搜索多次
        # print(i,j)
        print(curset)
        return
    if board[i][j] == tarword[index]:
        curset.append((i, j))
        m = len(board)
        n = len(board[0])
        for k in range(len(dir)):
            newi = i + dir[k][0]
            newj = j + dir[k][1]
            if 0 <= newi and newi < m and 0 <= newj and newj < n:
                if (newi,newj) not in curset:
                    search(newi, newj, board, tarword, index + 1, curset)
        curset.pop()
    else:
        return


def solution(board, tarword):
    for i in range(len(board)):
        for j in range(len(board[i])):
            curset = []
            search(i, j, board, tarword, 0, curset)


if __name__ == "__main__":
    board = load_data()
    tarword = input("Enter tarword")
    # print(len(tarword))
    solution(board, tarword)
