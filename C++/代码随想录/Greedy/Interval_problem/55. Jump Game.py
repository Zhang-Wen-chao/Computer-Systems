def canJump(nums):
    n = len(nums)
    dp = [False] * n
    dp[0] = True

    for i in range(1, n):
        for j in range(i):
            if dp[j] and j + nums[j] >= i:
                dp[i] = True
                break

    return dp[-1]

# 测试用例
print(canJump([2, 3, 1, 1, 4]))  # 应该输出 True
print(canJump([3, 2, 1, 0, 4]))  # 应该输出 False
