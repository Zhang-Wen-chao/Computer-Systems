def combinationSum4(nums, target):
    dp = [0] * (target + 1)
    dp[0] = 1

    for i in range(1, target + 1):
        for num in nums:
            if i - num >= 0:
                dp[i] += dp[i - num]

    return dp[target]

# 测试用例
print(combinationSum4([1, 2, 3], 4))  # 输出应该是 7
