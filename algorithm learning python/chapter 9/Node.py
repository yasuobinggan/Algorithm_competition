# @Time : 2019/5/26 21:31 
# @Author : Hxt
# @File : ClassNode.py
# @Software: PyCharm
# ======================================================================================================================

import sys

# 图的一个结点定义
class Node:
    def __init__(self, name):
        self.name = name

        self.mindistance = sys.maxsize # 初始化
        self.predecessor = None

    # 当前距离
    def set_mindistance(self, dist):
        self.mindistance = dist

    def get_mindistance(self):
        return self.mindistance

    # 前驱结点
    def set_predecessor(self, pred):
        self.predecessor = pred

    def get_predecessor(self):
        return self.predecessor
