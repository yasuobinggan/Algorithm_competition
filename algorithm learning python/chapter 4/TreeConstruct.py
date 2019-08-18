# @Time : 2019/6/28 8:37
# @Author : HXT
# @File : TreeConstruct.py
# @Software: PyCharm
# ======================================================================================================================

from BinaryTree import *
from collections import *


class TreeConstruct():
    index = 0  # 类变量

    def __init__(self):
        pass
        # self.node = Node()

    def restart(self):
        TreeConstruct.index = 0

    # 根据输入（一个对空结点标记的前序序列）建立动态二叉树（指向类实例）
    # 必须使用带返回值的递归形式
    def tree_pre_construct(self, root, prelist):  # root 是否需要返回值 # index应为全局变量

        if prelist[TreeConstruct.index] == "#":
            TreeConstruct.index += 1
            # # 无返回值
            # root = None
            # 有返回值
            return None
        else:
            # 有返回值
            root = Node()
            root.val = prelist[TreeConstruct.index]
            TreeConstruct.index += 1

            root.lchild = self.tree_pre_construct(root.lchild, prelist)
            root.rchild = self.tree_pre_construct(root.rchild, prelist)

            return root

            # 无返回值（错误）
            # root = Node()
            # root.val = prelist[TreeConstruct.index]
            # TreeConstruct.index += 1
            # # 不会给传入的"实例变量"开空间(已经实例化的变量函数会修改其中的值)
            # self.tree_pre_construct(root.lchild, depth + 1, prelist)
            # self.tree_pre_construct(root.rchild, depth + 1, prelist)

            # if depth == 0:
            #     return root
            #     # print("建树QIAN",id(realroot),id(root))
            #     # realroot = root.copy()
            #     # print("建树HOU",id(realroot),id(root))

    # 根据输入建立静态二叉树（指向标记）
    def tree_se_construct(self, treelist):
        N = int(input("Enter the amount of the tree"))
        treelist.append(Node())
        for i in range(1, N + 1):
            nodeinput = input("Enter the value, id of left, id of right").split(" ")
            # print("OUT",int(nodeinput[1]),int(nodeinput[2]))
            treelist.append(Node(id=i, value=int(nodeinput[0]), left=int(nodeinput[1]), right=int(nodeinput[2])))

    # 由前序和中序（空结点无标记）建立二叉树
    def tree_pi_construct(self, prelist, inlist, prest, preed, inst, ined):
        pass
