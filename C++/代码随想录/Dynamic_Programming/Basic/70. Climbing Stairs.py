def climbStairs(n):
    if n <= 2:
        return n

    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 2

    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

# 测试用例
print(climbStairs(2))  # 应该输出 2
print(climbStairs(3))  # 应该输出 3
print(climbStairs(4))  # 应该输出 5
