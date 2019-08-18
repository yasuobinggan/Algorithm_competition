# @Time : 2019/6/28 8:02 
# @Author : HXT
# @File : BinaryTree.py
# @Software: PyCharm
# ======================================================================================================================

class Node():
    def __init__(self, id=0, value="#", left=None, right=None):
        self.id = id  # 搭建静态树（对结点进行标记）

        self.val = value
        self.lchild = left
        self.rchild = right
