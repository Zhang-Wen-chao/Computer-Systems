def numSquares(n):
    dp = [float('inf')] * (n + 1)
    dp[0] = 0

    for i in range(1, n + 1):
        j = 1
        while j * j <= i:
            dp[i] = min(dp[i], dp[i - j * j] + 1)
            j += 1

    return dp[n]

# 测试用例
print(numSquares(12))  # 输出应该是 3，因为 12 = 4 + 4 + 4
print(numSquares(13))  # 输出应该是 2，因为 13 = 4 + 9
