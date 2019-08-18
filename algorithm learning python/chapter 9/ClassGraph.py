# @Time : 2019/5/26 21:28 
# @Author : Hxt
# @File : ClassGraph.py
# @Software: PyCharm

# 定义一个图
from collections import defaultdict


class Graph:
    def __init__(self):
        self.nodes = []
        self.edges = defaultdict(list)
        self.distances = {}

    def add_node(self, node):
        self.nodes.append(node)

    # 加入边(连接,距离)
    def add_edge(self, from_node, to_node, distance):
        self.edges[from_node].append(to_node)
        self.distances[(from_node, to_node)] = distance

    def name_get_node(self, name):
        for curnode in self.nodes:
            if name == curnode.name:
                return curnode
