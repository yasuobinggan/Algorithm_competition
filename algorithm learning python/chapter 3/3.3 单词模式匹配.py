# @Time : 2019/6/27 16:31 
# @Author : HXT
# @File : 3.3 单词模式匹配.py 
# @Software: PyCharm
# ======================================================================================================================

# 建立个互为自变量的满射关系：利用两个字典（哈希表）构建
def word_pattern(wordpattern, wordinput):
    hash = {}
    used = {}

    # 判断长度
    if len(wordpattern) != len(wordinput):
        return False

    for i in range(len(wordpattern)):
        if wordpattern[i] in hash.keys():
            if hash[wordpattern[i]] != wordinput[i]:
                return False
            else:
                continue
        else:
            if wordinput[i] in used.keys():
                return False

            used[wordinput[i]] = True  # 标记已经使用过
            hash[wordpattern[i]] = wordinput[i]  # 加入表

    return True


if __name__ == "__main__":
    wordpattern = input("输入数字序列表示单词模式").split(" ")
    wordinput = input("输入单词序列").split(" ")


    print(wordpattern)
    print(wordinput)

    flag = word_pattern(wordpattern, wordinput)
    if flag:
        print("匹配成功")
    else:
        print("匹配失败")
