def countSubstrings(s):
    n = len(s)
    dp = [[False] * n for _ in range(n)]
    count = 0

    # 单个字符总是回文串
    for i in range(n):
        dp[i][i] = True
        count += 1

    # 检查长度为 2 的子串
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            dp[i][i + 1] = True
            count += 1

    # 检查长度大于 2 的子串
    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j] and dp[i + 1][j - 1]:
                dp[i][j] = True
                count += 1

    return count

# 测试用例
print(countSubstrings("abc"))  # 输出应该是 3
print(countSubstrings("aaa"))  # 输出应该是 6
