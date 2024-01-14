def minDistance(word1, word2):
    m, n = len(word1), len(word2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j  # 如果 word1 为空，需要 j 次插入操作
            elif j == 0:
                dp[i][j] = i  # 如果 word2 为空，需要 i 次删除操作
            elif word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]  # 字符相同，不需要操作
            else:
                dp[i][j] = 1 + min(dp[i - 1][j],    # 删除
                                   dp[i][j - 1],    # 插入
                                   dp[i - 1][j - 1]) # 替换

    return dp[m][n]

# 测试用例
print(minDistance("horse", "ros"))  # 输出应该是 3
