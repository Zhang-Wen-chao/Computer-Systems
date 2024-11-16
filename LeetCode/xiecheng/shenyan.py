# 围棋盘是方形的，由纵横各19条线组成。19乘19形成了361个交叉点，也就是说，棋盘上总共有361个位置。
# 假设在棋盘的左上角有一枚棋子，我们要把它移动到右下角。每次只能向下或向右移动，且每次移动的距离只能为1步或2步。
# 例如，若该棋子在第3行第4列的位置，那么它此时可以有四种移动选择：向右移动1步、向右移动2步、向下移动1步、向下移动2步。 
# 请问从左上角移动到右下角有多少种不同的移动方式？ 450518481039956

def count_paths(n):
    dp = [[0]*n for _ in range(n)]
    dp[0][0] = 1  # 起点

    for i in range(n):
        for j in range(n):
            if i == 0 and j == 0:
                continue  # 起点已初始化
            total = 0
            if i - 1 >= 0:
                total += dp[i - 1][j]
            if i - 2 >= 0:
                total += dp[i - 2][j]
            if j - 1 >= 0:
                total += dp[i][j - 1]
            if j - 2 >= 0:
                total += dp[i][j - 2]
            dp[i][j] = total

    return dp[n - 1][n - 1]

n = 19  # 棋盘大小为 19x19
result = count_paths(n)
print(result)
