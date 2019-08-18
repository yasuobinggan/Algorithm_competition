# @Time : 2019/7/5 17:30 
# @Author : HXT
# @File : pd test.py
# @Software: PyCharm
# ======================================================================================================================
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# pandas的矩阵带有标签

# 创建pandas序列^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
s = pd.Series([1, 3, 6, np.nan, 44, 1])
print(s)

dates = pd.date_range("20160101", periods=6)
print(dates)
# .DataFrame是生成矩阵的函数
# index指示行 columns指示列
df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=["a", "b", "c", "d"])
print(df)

df1 = pd.DataFrame(np.arange(12).reshape((3, 4)))
print(df1)
# 字典形式构建pandas矩阵
df2 = pd.DataFrame({"A": 1.,
                    "B": pd.Timestamp("20130102"),
                    "C": pd.Series(1, index=list(range(4)), dtype="float32"),
                    "D": np.array([3] * 4, dtype="int32"),
                    "E": pd.Categorical(["test", "train", "test", "tarin"]),
                    "F": "foo"})
print(df2)
print(df2.index)  # 输出行标号
print(df2.columns)  # 输出列标号
print(df2.values)  # 输出元素值
print(df2.describe())  # 输出数值元素的相关特征数据
print(df2.T)
# 基于index(下标)数据排序 ascneding设置排序方式
df2.sort_index(axis=1, ascending=False)
df2.sort_index(axis=0, ascending=False)

# 对值进行排序(必须指定by的参数)
df2.sort_values(by="E")

# 选择数据^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
dates = pd.date_range("20130101", periods=6)
df = pd.DataFrame(np.arange(24).reshape(6, 4), index=dates, columns=["A", "B", "C", "D"])
# 选择一列数据
print(df["A"], df.A)  # 输出效果一致
# 选择多行数据
print(df[0:3], df["20130102":"20130104"])

# select by label:loc(3.7中可以index,label双选)
print(df.loc["20130102"])
print("利用标签输出\n", df.loc[:, ["A", "B"]])
print(df.loc["20130102", ["A", "B"]])
# select by position:iloc
print(df.iloc[3:5, 1:3])  # 保持左开右闭
print(df.iloc[[1, 3, 5], 1:3])
# mixed.selection:ix
print(df.ix[1:3, ["A", "C"]])

# 布尔筛选
print(df[df.A < 8])

print(df[df.A > 8][df.B > 17])
# 设置值^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
df.iloc[2, 2] = 1111
df.loc["20130101", "B"] = 2222
# df[df.A > 6] = 0 # df.A>0 的行全赋为0
df.A[df.A > 6] = 0
print(df)
# 新增一行
df["F"] = np.nan
df["E"] = pd.Series([1, 2, 3, 4, 5, 6], index=pd.date_range("20130101", periods=6))
print(df)
# 处理丢失的值^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
dates = pd.date_range("20130101", periods=6)
df = pd.DataFrame(np.arange(24).reshape(6, 4), index=dates, columns=["A", "B", "C", "D"])
df.iloc[0, 1] = np.nan
df.iloc[1, 2] = np.nan
# 丢弃np.nan相关的行
print(df.dropna(axis=0, how="any"))  # how = {"any","all"}
# 对np.nan的数据进行填充
print(df.fillna(value=0))
# 对数据进行判断
print(df.isnull())
# 是否存在丢失的数据
print(np.any(df.isnull()) == True)
# 导入导出^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
# 合并 concat^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
df1 = pd.DataFrame(np.ones((3, 4)) * 0, columns=["a", "b", "c", "d"])
df2 = pd.DataFrame(np.ones((3, 4)) * 1, columns=["a", "b", "c", "d"])
df3 = pd.DataFrame(np.ones((3, 4)) * 2, columns=["a", "b", "c", "d"])
res = pd.concat([df1, df2, df3], axis=0, ignore_index=True)  # 忽略标签的合并
print(res)
# 标签不一致的情况 join = outter扩展式合并 inner取相同的合并
df1 = pd.DataFrame(np.ones((3, 4)) * 0, columns=["a", "b", "c", "d"], index=[1, 2, 3])
df2 = pd.DataFrame(np.ones((3, 4)) * 1, columns=["b", "c", "d", "e"], index=[2, 3, 4])
res = pd.concat([df1, df2], join="inner", ignore_index=True)
print(res)
# 以df1的标签为标准合并
res = pd.concat([df1, df2], axis=1, join_axes=[df1.index])

# append
res = df1.append([df2, df3], ignore_index=True)
# 合并 merge^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
left = pd.DataFrame({"key": ["K0", "K1", "K2", "K3"],
                     "A": ["A0", "A1", "A2", "A3"],
                     "B": ["BO", "B1", "B2", "B3"]})
right = pd.DataFrame({"key": ["K0", "K1", "K2", "K3"],
                      "C": ["C0", "C1", "C2", "C3"],
                      "D": ["D0", "D1", "D2", "D3"]})

print(left)
print(right)
# 基于一个列(key)合并(类似于数据库)
res = pd.merge(left, right, on="key")
print(res)
# 基于两个key
left = pd.DataFrame({"key1": ["K0", "K0", "K1", "K2"],
                     "key2": ["K0", "K1", "K0", "K1"],
                     "A": ["A0", "A1", "A2", "A3"],
                     "B": ["BO", "B1", "B2", "B3"]})
right = pd.DataFrame({"key1": ["K0", "K1", "K1", "K2"],
                      "key2": ["K0", "K0", "K0", "K0"],
                      "C": ["C0", "C1", "C2", "C3"],
                      "D": ["D0", "D1", "D2", "D3"]})
# how = ["inner","outer","left","right"] (left,right 以哪一个矩阵的key为基础)
res = pd.merge(left, right, on=["key1", "key2"])
# indicator = True 显示合并方式
# left_index = True right_index = True 对比index进行合并
# 处理重复数据
boys = pd.DataFrame({"k":["k0","k1","k2"],"age":[1,2,3]})
girls = pd.DataFrame({"k":["k0","k0","k3"],"age":[4,5,6]})
res = pd.merge(boys,girls,on="k",suffixes=["_boy","_girl"],how="outer")

# plot图表^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
data = pd.Series(np.random.randn(1000),index=np.arange(1000))
data = data.cumsum()

data = pd.DataFrame(np.random.randn(1000,4),
                    index=np.arange(1000),
                    columns=list("ABCD"))
data = data.cumsum()
print(data.head())

data.plot()# plt.scatter 散点n
plt.show()