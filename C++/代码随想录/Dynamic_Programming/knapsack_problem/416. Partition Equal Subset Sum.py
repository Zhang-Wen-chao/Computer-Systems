def canPartition(nums):
    total_sum = sum(nums)
    if total_sum % 2 != 0:
        return False

    target = total_sum // 2
    dp = [False] * (target + 1)
    dp[0] = True

    for num in nums:
        for i in range(target, num - 1, -1):
            dp[i] = dp[i] or dp[i - num]

    return dp[target]

# 测试用例
print(canPartition([1, 5, 11, 5]))  # 输出应该是 True
print(canPartition([1, 2, 3, 5]))  # 输出应该是 False
