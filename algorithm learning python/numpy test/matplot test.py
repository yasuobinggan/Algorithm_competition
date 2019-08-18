# @Time : 2019/7/7 21:24 
# @Author : HXT
# @File : matplot test.py 
# @Software: PyCharm
# ======================================================================================================================

# import matplotlib
# from jedi.refactoring import inline
# %matplotlib inline

import matplotlib.pyplot as plt
import numpy as np

# plt 是静态类

# 基本用法^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
x = np.linspace(-1, 1, 50)
# y = 2 * x + 1
y = x ** 2
# plt.plot(x, y)  # 先横后纵
# plt.show()
# figure图像^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
x = np.linspace(-3, 3, 50)
y1 = 2 * x + 1
y2 = x ** 2
# plt.figure()

# 到下一个figure前,都属于这个figure
# plt.plot(x, y1)

plt.figure(num=3, figsize=(8, 5))  # 设置图片参数
# plt.plot(x, y2)
# plt.plot(x, y1, color="red", linewidth=1.0, linestyle="--")  # linestyle设置线的格式 虚线
# 坐标轴设置 1^^^^^^^^^^^^^^^^^^^^^^^^
# 设置坐标轴取值范围
plt.xlim((-1, 2))
plt.ylim((-2, 3))
# 描述坐标轴
plt.xlabel("I am X")
plt.ylabel("I am Y")
# 坐标轴节点设置
new_ticks = np.linspace(-1, 2, 5)  # -1~2 5个节点
print(new_ticks)
plt.xticks(new_ticks)
plt.yticks([-2, -1.8, -1, 1.22, 3], [r"$really\ bad$", r"$bad$", r"$normal$", r"$good$", r"$really\ good$"])
# 坐标轴设置 2^^^^^^^^^^^^^^^^^^^^^^^^
# gca = "get current axis"
ax = plt.gca()  # 获得轴
# 四个边框是脊梁
ax.spines["right"].set_color("none")  # 设置为none让其消失
ax.spines["top"].set_color("none")  #
# 设置x,y轴所在的脊
ax.xaxis.set_ticks_position("bottom")
ax.yaxis.set_ticks_position("left")
# 通过 值(数据) 选择  脊(轴)的位置
ax.spines["bottom"].set_position(("data", 0))  # 其他选择位置的参数 outward,axes
ax.spines["left"].set_position(("data", 0))
# legend 图例^^^^^^^^^^^^^^^^^^^^^^^^^
l1, = plt.plot(x, y2, label="up")
l2, = plt.plot(x, y1, color="red", linewidth=1.0, linestyle="--", label="down")
plt.legend(handles=[l1, l2, ], labels=["aaa", "bbb"], loc="best")
# Annotation 标注(添加注解 )^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
x = np.linspace(-3, 3, 50)
y = 2 * x + 1
plt.figure(num=1, figsize=(8, 5), )
plt.plot(x, y, )
ax = plt.gca()
ax.spines["right"].set_color("none")
ax.spines["top"].set_color("none")
ax.xaxis.set_ticks_position("bottom")
ax.yaxis.set_ticks_position("left")
ax.spines["bottom"].set_position(("data", 0))
ax.spines["left"].set_position(("data", 0))
# 添加点
x0 = 1
y0 = 2 * x0 + 1
# 画点
plt.scatter(x0, y0, s=50, color="b")  # s 为 size
# 设置虚线连接到x轴
plt.plot([x0, x0], [y0, 0], "k--", lw=2.5)
# method 1
plt.annotate(r"$2x+1=%s$" % y0, xy=(x0, y0), xycoords="data",xytext=(+30,-30),textcoords="offset points",fontsize=16,arrowprops=dict(arrowstyle="->",connectionstyle="arc3,rad=.2"))
# method 2
# plt.text(-3.7,3,r"$This\ is\ the\ some\ text.\ \mu\ \sigma_i\ \alpha_t$",fontdict={"size":16,"color":r""})
# r = row string

plt.show()
plt.close()  # 关闭图像
