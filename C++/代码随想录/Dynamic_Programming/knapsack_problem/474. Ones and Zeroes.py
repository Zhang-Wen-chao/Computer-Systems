def findMaxForm(strs, m, n):
    def count_zeros_ones(s):
        return s.count('0'), s.count('1')

    dp = [[[0 for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(len(strs) + 1)]

    for k in range(1, len(strs) + 1):
        num_zeros, num_ones = count_zeros_ones(strs[k - 1])
        for i in range(m + 1):
            for j in range(n + 1):
                if i >= num_zeros and j >= num_ones:
                    dp[k][i][j] = max(dp[k - 1][i][j], dp[k - 1][i - num_zeros][j - num_ones] + 1)
                else:
                    dp[k][i][j] = dp[k - 1][i][j]

    return dp[len(strs)][m][n]

# 测试用例
print(findMaxForm(["10", "0001", "111001", "1", "0"], 5, 3))  # 输出应该是 4
print(findMaxForm(["10", "0", "1"], 1, 1))  # 输出应该是 2
