def lengthOfLIS(nums):
    if not nums:
        return 0

    # dp[i] 表示以 nums[i] 结尾的最长递增子序列的长度
    dp = [1] * len(nums)

    for i in range(1, len(nums)):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)

# 测试用例
print(lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))  # 输出应该是 4
