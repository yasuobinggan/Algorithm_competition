# @Time : 2019/5/5 15:26
# @Author : Hxt
# @File : 1.3.py
# @Software: PyCharm

# mylist=[2,3,5,7,11,13,17,19,"integer","string","list",[123,456]]
# mylist.sort()
# print(mylist)
# print(mylist[11][0]/mylist[1])


# mylist=[2,3,5,7,13,17,19]
# mylist.append(23)
# print(mylist)
# mylist.insert(4,11)
# print(mylist)
# mylist.sort()
# print(mylist)
#
# numbers=[1,2,3,4,5,6]
# copylist=numbers
# copylist.pop()
# print(numbers,"\n",copylist)
#
# newlist=mylist+numbers
# newlist.sort()
# print(newlist)
# print(len(newlist))

# sample="abcdefg"
# print(list(sample),tuple(sample))
#
# list1=["abcdefg","hijk"]
# tuple1=(1,2,3,4,5)
# print(tuple(list1),list(tuple1))
# tuple1=(1)
# print(str(tuple1))


# num = []
# n = int(input("输入数据个数"))
# result = 1
# print("输入数据")
# str = input().split(" ")
# for i in range(n):
#
#     result *= number
#     print(number)
#     # num[i]=number
#     num.append(number)
# print(num)

# 字典
# letters={1:"a",2:"abc",4:"ewr"}
# print(letters)
# print(letters[2])
# for i in letters.items():
#     print(i)
# for j in letters:
#     print(j)

# 函数
# def Plus(a, b):
#     print(a + b)
# def Hello():
#     pass
# Plus(3,3)
# Hello()
#
#
# if __name__=='__main__':
#     print("HAO XUAN TING")
#
# numA=int(input("Enter the number of apples"))

# if __name__=='__main__':
#     numA=int(input("Enter apple number"))
#     numB=int(input("Enter pineapple number"))
#     numC=int(input("Enter watermelon number"))
#     print("Total:",Apple(numA),Pineapple(numB),Watermelon(numM))

MathGrade = -1
EnglistGrade = -1
HistoryGrade = -1


def get_MG_ML(mathgrade):
    mathgrade = int(input("Enter mathgrade"))
    while not (0 <= mathgrade and mathgrade <= 100):
        mathgrade = int(input("Enter mathgrade"))
    print("mathlevel:",)
    if mathgrade < 75:
        print("Bad")
    else:
        if mathgrade < 85:
            print("Good")
        else:
            print("Great")
    return mathgrade


def get_EG_EL(englishgrade):
    englishgrade = int(input("Enter englishgrade"))
    while not (0 <= englishgrade and englishgrade <= 100):
        englishgrade = int(input("Enter englishgrade"))
    print("englishlevel:",)
    if englishgrade < 80:
        print("Bad")
    else:
        if englishgrade < 90:
            print("Good")
        else:
            print("Great")
    return englishgrade


def get_HG_HL(historygrade):
    historygrade = int(input("Enter historygrade"))
    while not (0 <= historygrade and historygrade <= 100):
        historygrade = int(input("Enter historygrade"))
    print("history level:",)
    if historygrade < 70:
        print("Bad")
    else:
        if historygrade < 78:
            print("Good")
        else:
            print("Great")
    return historygrade


def get_TG(mathgrade, englistgrade, historygrade):
    print("totalgrade:",)
    return 1.1 * mathgrade + 1.1 * englistgrade + 0.8 * historygrade


def get_TL(totalgrade):
    print("total level:",)
    if totalgrade < 190:
        print("C")
    elif 190 <= totalgrade and totalgrade < 210:
        print("B")
    elif 210 <= totalgrade and totalgrade < 240:
        print("B+")
    elif 240 <= totalgrade and totalgrade < 270:
        print("A")
    else:
        print("A+")


if __name__ == '__main__':
    mathgrade = -1
    englishgrade = -1
    historygrade = -1

    mathgrade = get_MG_ML(mathgrade)
    englishgrade = get_EG_EL(englishgrade)
    historygrade = get_HG_HL(historygrade)

    totalgrade = get_TG(mathgrade, englishgrade, historygrade)
    print(totalgrade)
    get_TL(totalgrade)
