# @Time : 2019/6/27 17:35 
# @Author : HXT
# @File : 3.4 猜词游戏.py 
# @Software: PyCharm
# ======================================================================================================================
def number_split(number):
    numberlist = []
    while number > 0:
        numberlist.append(number % 10)
        number //= 10
    return numberlist


def getHint(serect, guess):
    A: int = 0
    for i in range(len(serect)):
        if serect[i] == guess[i]:
            A += 1

    B = 0
    serect_dict = {}
    guess_dict = {}

    for i in range(len(serect)):
        if serect[i] != guess[i]:
            if serect[i] in serect_dict:
                serect_dict[serect[i]] += 1
            else:
                serect_dict[serect[i]] = 1
            if serect[i] in guess_dict:
                guess_dict[serect[i]] += 1
            else:
                guess_dict[serect[i]] = 1

    for ele in serect_dict:
        if ele in guess_dict:
            B += min(serect_dict[ele], guess_dict[ele])

    print("A: %d\tB: %d"%(A,B))


if __name__ == "__main__":
    serect = int(input("Enter serect number"))
    guess = int(input("Enter guess number"))

    serect = number_split(serect)
    guess = number_split(guess)

    print(serect,guess)

    getHint(serect, guess)
