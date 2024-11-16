# 读取初始输入
n, q = map(int, input().split())
a = list(map(int, input().split()))  # 初始每种卡牌的数量

# 判断是否有任何一种卡牌数量大于等于2
def can_win(cards):
    for count in cards:
        if count >= 2:
            return True
    return False

# 处理初始状态的卡牌
if can_win(a):
    print(1)  # 可以通过偷看一张牌获胜
else:
    print(-1)  # 无法获胜

# 处理 q 轮操作
for _ in range(q):
    operation = input().split()
    op = operation[0]
    l, r, x = map(int, operation[1:])
    
    # 执行增加或减少卡牌操作
    if op == '+':
        for i in range(l - 1, r):
            a[i] += x
    elif op == '-':
        for i in range(l - 1, r):
            a[i] -= x
    
    # 判断当前状态是否能获胜
    if can_win(a):
        print(1)  # 可以通过偷看一张牌获胜
    else:
        print(-1)  # 无法获胜
