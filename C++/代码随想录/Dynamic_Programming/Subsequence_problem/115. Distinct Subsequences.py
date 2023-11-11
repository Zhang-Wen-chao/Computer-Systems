def numDistinct(s, t):
    m, n = len(s), len(t)
    if m < n:
        return 0

    # dp[i][j] 表示 s[:i] 中有多少个子序列等于 t[:j]
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    # 当 t 为空字符串时，s 的每个子串都有一个空子序列与之匹配
    for i in range(m + 1):
        dp[i][0] = 1

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s[i - 1] == t[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[m][n]

# 测试用例
print(numDistinct("rabbbit", "rabbit"))  # 输出应该是 3
