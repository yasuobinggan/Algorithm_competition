# @Time : 2019/7/9 9:24 
# @Author : HXT
# @File : 活动安排问题.py 
# @Software: PyCharm
# ======================================================================================================================
def load_data():
    N = int(input("Enter the number of activity"))
    actlist = []
    for i in range(N):
        (st, ed) = tuple(input("Enter st,ed").split(" "))
        (st, ed) = (int(st), int(ed))
        actlist.append((st, ed))
    return actlist


def choose(actlist):
    anslist = []
    anslist.append(actlist[0])
    ed = actlist[0]
    for i in range(1, len(actlist)):
        if actlist[i][0] >= ed[1]:
            anslist.append(actlist[i])
            ed = actlist[i]
    print(anslist)

if __name__ == "__main__":
    actlist = load_data()
    # print(actlist)
    actlist.sort(key=lambda x: x[1])
    # print(actlist)
    choose(actlist)