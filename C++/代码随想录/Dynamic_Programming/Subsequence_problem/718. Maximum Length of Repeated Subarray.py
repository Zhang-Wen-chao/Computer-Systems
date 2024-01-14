def findLength(A, B):
    m, n = len(A), len(B)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    maxLength = 0

    for i in range(m - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            if A[i] == B[j]:
                dp[i][j] = dp[i + 1][j + 1] + 1
                maxLength = max(maxLength, dp[i][j])

    return maxLength

# 测试用例
print(findLength([1,2,3,2,1], [3,2,1,4,7]))  # 输出应该是 3
print(findLength([0,0,0,0,0], [0,0,0,0,0]))  # 输出应该是 5
