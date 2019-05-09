# @Time : 2019/5/4 20:31 
# @Author : Hxt
# @File : 1.2.py 
# @Software: PyCharm


# 分支结构

# year=int(input("Enter a year"))
# if (year%4==0 and year %100 != 0) or year%400 == 0:
#     print("是闰年")
# else:
#     print("不是闰年")
#
# i=int(input("输入一个数字"))
# if (i>0):
#     print("i>0\n")
#
# age=int(input("输入年龄判断票价"))
# if age<0:
#     print("错误输入")
# else:
#     if age<7:
#         print("FREE")
#     elif age>=7 and age<=14:
#         print("HALF PRICE")
#     elif age>=60:
#         print("HALF PRICE")
#     else:
#         print("FULL")

# 循环结构

# arr=[1,2,3,4,5,6,7,8,9,10]
# # print(len(arr))
# for i in range(len(arr)):
#     # if arr[i]%5==0:
#     #     continue
#     print(str(i)+"\t"+str(arr[i])+"\n")
# # print(arr[9])

# bornyear = int(input("Enter born year"))
# thisyear = int(input("Enter this year"))
# while bornyear > thisyear:
#     print("重新输入")
#     bornyear = int(input("Enter born year"))
#     thisyear = int(input("Enter this year"))
# else:
#     print("Your age", thisyear - bornyear)
# n = int(input("Enter a number"))
# result = 1
# for i in range(1, n+1):
#     print(i)
#     result *= i
# print("The answer is", result)
# count=0
# while True:
#     if count%5==0:
#         count+=1
#         continue
#     elif count==12:
#         break
#     print(count)
#     count+=1

a = int(input("Enter a number"))
b = int(input("Enter a number"))
print(type(a))
print(type(b))
if b == 0:
    print("ERROR")
else:
    if a % b == 0:
        print(int(a / b), type(int(a / b)))
    else:
        print(a / b, type(a / b))
