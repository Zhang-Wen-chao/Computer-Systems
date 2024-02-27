def lastStoneWeightII(stones):
    total_weight = sum(stones)
    dp = [False] * (total_weight // 2 + 1)
    dp[0] = True

    for stone in stones:
        for j in range(len(dp) - 1, stone - 1, -1):
            dp[j] = dp[j] or dp[j - stone]

    for i in range(len(dp) - 1, -1, -1):
        if dp[i]:
            return total_weight - 2 * i

    return 0

# 测试用例
print(lastStoneWeightII([2,7,4,1,8,1]))  # 输出应该是 1
print(lastStoneWeightII([31,26,33,21,40]))  # 输出应该是 5
