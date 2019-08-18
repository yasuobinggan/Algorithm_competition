# @Time : 2019/5/27 21:57 
# @Author : Hxt
# @File : 6.6 Sudoko.py 
# @Software: PyCharm

class Solution():
    def solveSudoku(self, board):
        self.helper(board, 0)

    def helper(self, board, index):
        if index >= 81:
            self.printSolution(board)
            return
        if board[index] == 0:
            for i in range(1, 10):
                if self.isValid(board, index, i):
                    board[index] = i
                    self.helper(board, index + 1)
                    board[index] = 0
        else:
            self.helper(board, index + 1)

    def printSolution(self, board):
        for i in range(0, 81, 9):
            print(board[i:i + 9])

    def isValid(self, board, index, num):
        row = index // 9
        column = index % 9
        for i in range(index + 9, 81, 9):
            if board[i] == num:
                return False
        for i in range(index - 9, -1, -9):
            if board[i] == num:
                return False
        for i in range(9 * row, 9 * (row + 1)):
            if board[i] == num:
                return False
        for i in range(row - row % 3, 3 + row - row % 3):
            for j in range(column - column % 3, 3 + column - column % 3):
                if board[j + i * 9] == num:
                    return False
        return True

# board=[4, 1, 0, 0, 0, 7, 8, 5, 0,
#      8, 0, 6, 0, 0, 0, 0, 0, 9,
#      0, 2, 0, 0, 9, 0, 6, 0, 0,
#      0, 0, 4, 0, 0, 0, 0, 1, 2,
#      2, 0, 0, 5, 8, 0, 0, 7, 0,
#      0, 0, 0, 0, 0, 0, 5, 0, 0,
#      0, 0, 0, 7, 0, 2, 0, 0, 0,
#      0, 0, 8, 0, 1, 0, 0, 0, 0,
#      0, 7, 0, 0, 6, 0, 0, 0, 0]
#
#
# mysolution=Solution()
# mysolution.solveSudoku(board)

Solution().solveSudoku(
    [4, 1, 0, 0, 0, 7, 8, 5, 0,
     8, 0, 6, 0, 0, 0, 0, 0, 9,
     0, 2, 0, 0, 9, 0, 6, 0, 0,
     0, 0, 4, 0, 0, 0, 0, 1, 2,
     2, 0, 0, 5, 8, 0, 0, 7, 0,
     0, 0, 0, 0, 0, 0, 5, 0, 0,
     0, 0, 0, 7, 0, 2, 0, 0, 0,
     0, 0, 8, 0, 1, 0, 0, 0, 0,
     0, 7, 0, 0, 6, 0, 0, 0, 0]
)
