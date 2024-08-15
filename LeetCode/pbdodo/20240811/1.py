# 多多制定了一个庞大的旅行计划。具体而言，多多准备去（N）个景点游玩。
# 它还为每个景点设定了优先级，必须先前往优先级高的景点游玩，然后才能前往优先级低的景点，各个景点优先级互不相同。
# 同时由于各大景点都十分火爆，多多只能在已预约的第（Xi）天前往景点（i），
# 如果无法按约前往，则只能每过（D_i）天再次前往。即，多多只能在第（X_i）、（X_i+D_i）、（X_i+2D_i）、…・.天前去景点（1）。
# 多多一天最多游玩一个景点，请问至少需要几天多多才能完成它的旅行计划。

# 输入描述
# 第一行，一个整数（N），表示有（N）个景点。
# 接下来（N）行，第（i）行有三个整数：（P_i）、（X_i）、（D_i）。
# •（P_i） 是景点（i）的优先级，数字越小，表示优先级越高。
# •（X_i） 是针对景点（i）的初次预约时间。
# •（D_i） 是允许再次前往的天数间隔。
# 输入限制：
# ・（1≤N,P_i≤ 100,000）
# • (1 ≤ X_i, D_i < 1, 000)
# 输出描述
# 输出至少需要的天数。

# Input 1:
# 3
# 3 2 3
# 1 3 2
# 2 2 2
# output 1: 5
# 2号景点优先级最高。第3天前往2号景点，然后只能在第4天前往3号景点，第5天前往1号景点,因此共5天。

# Input 2:
# 2
# 1 2 2
# 2 1 3
# output 2: 4
# 1号景点优先级最高。第2天前往1号景点，然后只能在第4天前往2号景点，因此共4天。

import sys

n = int(input())  # 景点数量
sights = []

for _ in range(n):
    priority, first_day, interval = map(int, input().split())
    sights.append((priority, first_day, interval))

# 按优先级从高到低排序，优先级数字越小，优先级越高
sights.sort(key=lambda x: x[0])

current_day = 0  # 当前游玩到的天数

for _, first_day, interval in sights:
    if first_day > current_day:
        current_day = first_day
    else:
        if (current_day - first_day) % interval == 0:
            current_day = first_day + (current_day - first_day + interval) // interval * interval
        else:
            current_day = first_day + (current_day - first_day + interval - 1) // interval * interval

print(current_day)