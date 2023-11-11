def uniquePaths(m, n):
    dp = [[1] * n for _ in range(m)]

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

    return dp[m - 1][n - 1]

# 测试用例
print(uniquePaths(3, 7))  # 应该输出 28
print(uniquePaths(3, 2))  # 应该输出 3
