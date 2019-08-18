# @Time : 2019/6/28 9:13 
# @Author : HXT
# @File : TreeTravel.py
# @Software: PyCharm
# ======================================================================================================================
from BinaryTree import *
import collections


def pretravel(root):
    if root == None:
        return
    else:
        print(root.val)
        pretravel(root.lchild)
        pretravel(root.rchild)


def intravel(root):
    if root == None:
        return
    else:
        intravel(root.lchild)
        print(root.val)
        intravel(root.rchild)


def postravel(root):
    if root == None:
        return
    else:
        postravel(root.lchild)
        postravel(root.rchild)
        print(root.val)


def layertravel(root):
    treequeue = collections.deque()
    if root != None:
        treequeue.append(root)
    while len(treequeue) != 0:
        curnode = treequeue.pop()
        print(curnode.val)

        if curnode.lchild != None:
            treequeue.append(curnode.lchild)
        if curnode.rchild != None:
            treequeue.appen(curnode.rchild)
