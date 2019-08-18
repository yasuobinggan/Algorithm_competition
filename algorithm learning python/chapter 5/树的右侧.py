# @Time : 2019/7/1 21:23
# @Author : HXT
# @File : 树的右侧.py
# @Software: PyCharm
# ======================================================================================================================
class TreeNode():
    def __init__(self, id=-1, value="#"):
        self.id = id
        self.val = value
        self.lchild = None
        self.rchild = None


def tree_construct():
    root = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node6 = TreeNode(6)
    node7 = TreeNode(7)

    root.lchild, root.rchild = node2, node3
    node2.lchild, node2.rchild = node4, node5
    node3.lchild = node6
    node5.lchild = node7

    return root


def bfs(root):
    queue = []
    queue.append(root)

    while len(queue) > 0:
        print(queue[-1].id)

        temp = []
        for i in range(len(queue)):
            if queue[i].lchild != None:
                temp.append(queue[i].lchild)
            if queue[i].rchild != None:
                temp.append(queue[i].rchild)
        queue = temp



if __name__ == "__main__":
    root = tree_construct()
    bfs(root)
