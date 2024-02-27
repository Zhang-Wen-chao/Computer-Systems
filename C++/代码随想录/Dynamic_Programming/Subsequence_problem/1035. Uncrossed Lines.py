def maxUncrossedLines(A, B):
    m, n = len(A), len(B)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if A[i - 1] == B[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[m][n]

# 测试用例
print(maxUncrossedLines([1,4,2], [1,2,4]))  # 输出应该是 2
print(maxUncrossedLines([2,5,1,2,5], [10,5,2,1,5,2]))  # 输出应该是 3
