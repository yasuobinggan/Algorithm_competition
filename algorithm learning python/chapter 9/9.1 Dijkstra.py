# @Time : 2019/5/26 21:32 
# @Author : Hxt
# @File : 9.1 Dijkstra.py
# @Software: PyCharm
# ======================================================================================================================
from ClassGraph import Graph
from Node import Node
import sys

def Gmap_construct():
    Gmap = Graph()
    root = Node("A")
    Gmap.add_node(root)
    Gmap.add_node(Node("B"))
    Gmap.add_node(Node("C"))
    Gmap.add_node(Node("D"))
    Gmap.add_node(Node("E"))
    Gmap.add_node(Node("F"))

    # Gmap.add_edge(Node("A"), Node("B"), 10)
    # Gmap.add_edge(Node("B"), Node("A"), 10)
    # Gmap.add_edge(Node("B"), Node("D"), 5)
    # Gmap.add_edge(Node("D"), Node("B"), 5)
    # Gmap.add_edge(Node("D"), Node("F"), 10)
    # Gmap.add_edge(Node("F"), Node("D"), 10)
    # Gmap.add_edge(Node("F"), Node("E"), 20)
    # Gmap.add_edge(Node("E"), Node("F"), 20)
    # Gmap.add_edge(Node("E"), Node("C"), 12)
    # Gmap.add_edge(Node("C"), Node("E"), 12)
    # Gmap.add_edge(Node("C"), Node("A"), 15)
    # Gmap.add_edge(Node("A"), Node("C"), 15)
    Gmap.add_edge("A", "B", 10)
    Gmap.add_edge("B", "A", 10)
    Gmap.add_edge("B", "D", 5)
    Gmap.add_edge("D", "B", 5)
    Gmap.add_edge("D", "F", 10)
    Gmap.add_edge("F", "D", 10)
    Gmap.add_edge("F", "E", 20)
    Gmap.add_edge("E", "F", 20)
    Gmap.add_edge("E", "C", 12)
    Gmap.add_edge("C", "E", 12)
    Gmap.add_edge("C", "A", 15)
    Gmap.add_edge("A", "C", 15)
    Gmap.add_edge("A", "E", 30)
    Gmap.add_edge("E", "A", 30)
    Gmap.add_edge("B", "E", 14)
    Gmap.add_edge("E", "B", 14)
    Gmap.add_edge("C", "D", 12)
    Gmap.add_edge("D", "C", 12)

    return Gmap, root


def dijsktra(Gmap, root):
    visited = set()

    root.set_mindistance(0)
    root.set_predecessor(None)

    for i in range(len(Gmap.nodes)):
        minnode = Node("#")
        for u in Gmap.nodes:# minnode,u is node
            if u.name not in visited and u.mindistance <= minnode.mindistance:
                minnode = u
                break

        visited.add(minnode.name)# name set

        for v in Gmap.edges[minnode.name]:# v is name
            if v not in visited and Gmap.distances[(minnode.name, v)] + minnode.mindistance < Gmap.name_get_node(v).mindistance:
                Gmap.name_get_node(v).mindistance = Gmap.distances[(minnode.name, v)] + minnode.mindistance
                Gmap.name_get_node(v).predecessor = minnode
                print(Gmap.name_get_node(v).mindistance)
                print(Gmap.name_get_node(v).predecessor)


# 输出最短路径
def get_path(node):
    print(node.name)
    curnode = node
    while curnode.predecessor != None:
        curnode = curnode.predecessor
        print(curnode.name)



if __name__ == "__main__":
    Gmap, root = Gmap_construct()

    dijsktra(Gmap, root)

    for i in range(len(Gmap.nodes)):
        print("NODE PATH OUT",Gmap.nodes[i].name,Gmap.nodes[i].mindistance)
        get_path(Gmap.nodes[i])
