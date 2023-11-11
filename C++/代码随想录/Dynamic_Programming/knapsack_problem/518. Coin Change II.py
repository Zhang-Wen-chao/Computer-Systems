def change(amount, coins):
    dp = [0] * (amount + 1)
    dp[0] = 1

    for coin in coins:
        for x in range(coin, amount + 1):
            dp[x] += dp[x - coin]

    return dp[amount]

# 测试用例
print(change(5, [1, 2, 5]))  # 输出应该是 4
print(change(3, [2]))  # 输出应该是 0
print(change(10, [10]))  # 输出应该是 1
