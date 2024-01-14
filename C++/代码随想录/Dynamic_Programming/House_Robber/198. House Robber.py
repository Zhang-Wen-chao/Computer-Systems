def rob(nums):
    if not nums:
        return 0
    if len(nums) <= 2:
        return max(nums)

    dp = [0] * len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])

    for i in range(2, len(nums)):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    return dp[-1]

# 测试用例
print(rob([1, 2, 3, 1]))  # 输出应该是 4
print(rob([2, 7, 9, 3, 1]))  # 输出应该是 12
