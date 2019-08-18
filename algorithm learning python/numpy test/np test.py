# @Time : 2019/7/4 14:49 
# @Author : HXT
# @File : np test.py 
# @Software: PyCharm
# ======================================================================================================================
import numpy as np
import pandas

# 也许简单的来记就是axis=0代表往跨行（down)，而axis=1代表跨列（across)，作为方法动作的副词（译者注）
#
# 换句话说:
#
#     使用0值表示沿着每一列或行标签\索引值向下执行方法
#     使用1值表示沿着每一行或者列标签模向执行对应的方法


# 分清数组与矩阵

# 数组******************************************************************************************************
array1 = np.array([[1, 2, 3],
                   [2, 3, 4]], dtype=np.int)

# 创建数组^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
# int64 精度，占用空间 大于 int32
print(array1)
print(array1.dtype)
print("number of dim:", array1.ndim)  # 是几维数组
print("shape:", array1.shape)  # 形状
print("size", array1.size)  # 数组有多少元素

# 建立特殊的矩阵^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
azero = np.zeros((3, 4), dtype=np.int16)
print("zero\n", azero)
aone = np.ones((3, 4), dtype=np.int16)
print("one\n", aone)
aempty = np.empty((3, 4))
print("empty\n", aempty)

# reshape只能约束固定大小的矩阵^^^^^^^^^^^^^^^^^^^^^^^^^^^
# arange 功能与 range 相似
a = np.arange(10, 20, 2).reshape((5, 1))  # 左闭右开
print("arange\n", a)

# 创建等差数列^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
a = np.linspace(1, 10, 10).reshape((2, 5))  # 第三个参数是等差数列的项数
print(type(a))
print("linspace\n", a)

# 创建等比数列^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
a = np.logspace(1, 10, 10).reshape((2, 5))
print("logspace\n", a)

# 基础运算^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
a = np.array([10, 20, 30, 40])
b = np.arange(4)
c = a - b
print("减法运算\n", a, b, c)
c = a + b
print("加法运算\n", a, b, c)
c = b ** 2  # 数组每个元素自乘
print("幂积运算\n", c)
# 三角函数运算 参数是弧度制
c = np.sin(a) * 180
# [ -97.92379996  164.33014513 -177.84569234  134.12036889]
print("三角函数\n", c)
# Bool判断
print(c)
flag = (c <= 0)
print("Bool判断", type(flag))
print(flag)
# 数组元素对应相乘,数组以矩阵的方式相乘
a = np.array([[1, -1], [2, 1]])
b = np.array([[1, -1], [2, 1]])
c = a * b  # 对应相乘
print("对应相乘\n", a, "\n", b, "\n", c)
c = np.dot(a, b)  # 矩阵乘
c = a.dot(b)
print("矩阵乘\n", a, "\n", b, "\n", c)
# 生成一个2 * 4的随机化矩阵
a = np.random.random((2, 4))
print("random\n", a)
# np.sum()
# np.min()
# np.max()
print(np.sum(a))
print(np.min(a))
print(np.max(a))

print(np.sum(a, axis=0))  # 指定具体的轴(0:第一维,1:第二维) axis基于数组
print(np.min(a, axis=1))

# 基础运算2^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
a = np.arange(2, 14).reshape((3, 4))
print(np.argmin(a))  # 返回最小值索引
print(np.argmax(a))  # 返回最大值索引
# 平均值
print(np.mean(a))
print(np.average(a))
# 中位数
print(np.median(a))
# 元素数相同,类似于前缀和
print(np.cumsum(a))
# 相邻两个数之间的差
print(np.diff(a))
# 输出非零元素的行位置,列位置
print(np.nonzero(a))

# 二维数组对每一行排序
a = np.arange(14, 2, -1).reshape((3, 4))
print(a)
print("排序\n", np.sort(a))  # 升序排序
# 二维数组转置
print(np.transpose(a))
print(a.T)
print((a.T).dot(a))
# clip(某种滤波)
print(np.clip(a, 5, 9))
print(np.clip(a, 9, 5))

# 索引^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
# 从零开始
a = np.arange(3, 15)
print(a[3])
a = a.reshape(3, 4)
print(a[1][1])
print(a[2, :])
print(a[:, 1])
print(a[1, 1:2])

for row in a:
    print(row)
for column in a.T:  # 按列迭代
    print(column)

# a.flatten()返回一个展开后的一维数组
for item in a.flat:  # flat 高维数组展开(返回迭代器)
    print(item)

# 合并数组^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
A = np.array([1, 1, 1])
B = np.array([2, 2, 2])
a = np.array([3, 3, 3])
b = np.array([3, 3, 3])
c = np.array([3, 3, 3])

C = np.vstack((A, B, a, b, c))  # 竖直方向合并
print("竖直方向合并", A.shape, C.shape)
D = np.hstack((A, B))  # 水平方向合并
print(A.shape, D.shape)
# 将一个行向量-》列向量
A = A.reshape(A.size, 1)
print(A.shape)
# 纵向或横向合并(必须在以下这种情况下)
A = np.array([1, 1, 1])[:, np.newaxis]
B = np.array([2, 2, 2])[:, np.newaxis]
C = np.concatenate((A, B, B, A), axis=1)  # 水平方向合并
print("np.newaxis\n", C)

# 分割数组^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
A = np.arange(12).reshape(3, 4)  # 新的语法格式
print(np.split(A, 2, axis=1))  # 分割成相等的几块 # 第二个参数是分成几块 # axis标记对哪一维进行操作
print(np.array_split(A, 3, axis=1))  # 不等量分割 #
# np.vsplit() 对垂直的进行分割
# np.hsplit() 对横向的进行分割

# 深复制 浅复制
a = np.arange(12).reshape(3, 4)
b = a  # 浅复制
b = a.copy()  # 深复制
b = a[:, :]
print("查看复制\n", b.shape)

