# @Time : 2019/6/28 21:21 
# @Author : HXT
# @File : 4.3 Catch the thief.py 
# @Software: PyCharm
# ======================================================================================================================
from BinaryTree import *
from TreeConstruct import *


def pretravel(root, prelist):
    if root.id == 0:
        return
    else:
        prelist.append(root.id)
        pretravel(treelist[root.lchild])
        pretravel(treelist[root.rchild])


def search_dfs(root):# [不偷，偷]
    if root.id == 0:
        return [0,0]
    else:
        left = search_dfs(treelist[root.lchild])
        right = search_dfs(treelist[root.rchild])
        robvalue = left[0] + right[0] + root.val
        skipvalue = max(left) + max(right)
        return [skipvalue,robvalue]



def get_ans(root):
    ans = search_dfs(root)
    ans = max(ans)
    print("小偷能获得的最大财产%d"%(ans))


if __name__ == "__main__":
    print("建立二叉树")
    treelist = []
    '''
    3 2 3
    4 4 5
    5 6 0
    1 0 0
    3 0 0
    1 0 0
    '''
    TreeConstruct().tree_se_construct(treelist)
    # print(treelist)
    # prelist = []
    # pretravel(treelist[1], prelist)
    # print(prelist)

    get_ans(treelist[1])