# @Time : 2019/6/28 11:10 
# @Author : HXT
# @File : Treetest.py
# @Software: PyCharm
# ======================================================================================================================
from BinaryTree import *
from TreeConstruct import *
from TreeTravel import *

if __name__ == "__main__":

    #1 2 4 # # 5 # # 3 # 6 # #
    #prelist = input("Enter the prelist of the tree").split(" ")
    prelist = "1 2 4 # # 5 # # 3 # 6 # #".split(" ")
    print(prelist)

    tree1 = Node()
    # 返回值版
    tree1 = TreeConstruct().tree_pre_construct(tree1,prelist)

    # 无返回值版（错误）
    # depth = 0
    # tree1 = TreeConstruct().tree_pre_construct(tree1, depth, prelist)

    print("前序遍历")
    pretravel(tree1)
# <BinaryTree.Node object at 0x0000018D208412B0>