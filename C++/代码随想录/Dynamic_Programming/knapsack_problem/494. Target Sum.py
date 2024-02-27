def findTargetSumWays(nums, target):
    total_sum = sum(nums)
    if total_sum < target or (total_sum + target) % 2 == 1:
        return 0

    return subsetSum(nums, (total_sum + target) // 2)

def subsetSum(nums, sum_val):
    dp = [0] * (sum_val + 1)
    dp[0] = 1

    for num in nums:
        for i in range(sum_val, num - 1, -1):
            dp[i] += dp[i - num]

    return dp[sum_val]

# 测试用例
print(findTargetSumWays([1, 1, 1, 1, 1], 3))  # 输出应该是 5
print(findTargetSumWays([1], 2))  # 输出应该是 0
