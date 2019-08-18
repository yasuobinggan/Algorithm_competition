# @Time : 2019/7/6 20:32 
# @Author : HXT
# @File : 组合数问题.py 
# @Software: PyCharm
# ======================================================================================================================
def choose(list, targetindex, anslist, index):
    if targetindex == len(anslist):
        print(anslist)
        return
    if index == len(list):
        return
    else:
        anslist.append(list[index])
        choose(list, targetindex, anslist, index + 1)
        anslist.remove(list[index])
        choose(list, targetindex, anslist, index + 1)


if __name__ == "__main__":
    # list = input("Enter the list").split(" ")
    list = ["微积分", "音乐", "烹饪", "设计"]
    targetindex = int(input("Enter targetindex"))
    anslist = []
    index = 0
    choose(list, targetindex, anslist, index)
