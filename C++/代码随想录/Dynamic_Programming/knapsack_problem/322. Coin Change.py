def coinChange(coins, amount):
    dp = [amount + 1] * (amount + 1)
    dp[0] = 0

    for i in range(1, amount + 1):
        for coin in coins:
            if i - coin >= 0:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[amount] if dp[amount] != amount + 1 else -1

# 测试用例
print(coinChange([1, 2, 5], 11))  # 输出应该是 3，因为 11 = 5 + 5 + 1
print(coinChange([2], 3))         # 输出应该是 -1，因为无法组成金额 3
