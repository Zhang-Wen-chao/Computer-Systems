def maxProfit(k, prices):
    if not prices:
        return 0

    n = len(prices)
    if k >= n // 2:
        return sum(max(prices[i + 1] - prices[i], 0) for i in range(n - 1))

    dp = [[0] * (k + 1) for _ in range(n)]
    for j in range(1, k + 1):
        max_diff = -prices[0]
        for i in range(1, n):
            dp[i][j] = max(dp[i - 1][j], prices[i] + max_diff)
            max_diff = max(max_diff, dp[i - 1][j - 1] - prices[i])

    return dp[-1][-1]

# 测试用例
print(maxProfit(2, [2,4,1]))          # 输出应该是 2
print(maxProfit(2, [3,2,6,5,0,3]))    # 输出应该是 7
