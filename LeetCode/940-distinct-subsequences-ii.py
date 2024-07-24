def distinctSubseqII(s: str) -> int:
    MOD = 10**9 + 7
    n = len(s)
    dp = [0] * (n + 1)
    dp[0] = 1  # base case: the empty subsequence
    
    last = {}
    
    for i in range(1, n + 1):
        dp[i] = (2 * dp[i - 1]) % MOD
        if s[i - 1] in last:
            dp[i] = (dp[i] - dp[last[s[i - 1]] - 1]) % MOD
        last[s[i - 1]] = i
    
    return (dp[n] - 1) % MOD

# 示例用法
s = "abc"
print(distinctSubseqII(s))  # 输出: 7
s1 = "aba"
print(distinctSubseqII(s1))  # 输出: 6
s2 = "aaa"
print(distinctSubseqII(s2))  # 输出: 3
