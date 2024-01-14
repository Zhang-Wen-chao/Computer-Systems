def rob(nums):
    def simple_rob(start, end):
        if end - start <= 1:
            return nums[start]

        dp = [0] * len(nums)
        dp[start] = nums[start]
        dp[start + 1] = max(nums[start], nums[start + 1])

        for i in range(start + 2, end):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

        return dp[end - 1]

    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]

    return max(simple_rob(0, len(nums) - 1), simple_rob(1, len(nums)))

# 测试用例
print(rob([2, 3, 2]))  # 输出应该是 3
print(rob([1, 2, 3, 1]))  # 输出应该是 4
