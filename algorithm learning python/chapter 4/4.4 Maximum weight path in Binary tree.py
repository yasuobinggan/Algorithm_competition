# @Time : 2019/6/29 9:48 
# @Author : HXT
# @File : 4.4 Maximum weight path in Binary tree.py 
# @Software: PyCharm
# ======================================================================================================================
# 二叉树(带负值)中的最大路径和
from TreeConstruct import *
import sys


def search_dfs(root):  # [stop,unstop]
    if root.id == 0:
        return [-sys.maxsize, -sys.maxsize]
    else:
        left = search_dfs(treelist[root.lchild])
        right = search_dfs(treelist[root.rchild])
        stop = max(left[0], right[0], left[1] + right[1] + root.val)
        unstop = max(left[1] + root.val, right[1] + root.val, root.val)
        return [stop, unstop]


def get_ans(root):
    ans = search_dfs(root)
    print(max(ans))


if __name__ == "__main__":
    print("建立二叉树")
    treelist = []
    '''
    1 2 3
    2 4 5
    -2 6 7
    10 0 0
    12 0 0
    2 0 0
    1 0 0
    '''
    TreeConstruct().tree_se_construct(treelist)

    get_ans(treelist[1])
