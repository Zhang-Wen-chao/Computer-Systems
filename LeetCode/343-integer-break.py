def integerBreak(n: int) -> int:
    # 初始化 dp 数组，其中 dp[i] 表示将整数 i 拆分后得到的最大乘积
    dp = [0] * (n + 1)
    
    # 边界条件
    dp[1] = 1
    
    # 填充 dp 数组
    for i in range(2, n + 1):
        for j in range(1, i):
            dp[i] = max(dp[i], j * (i - j), j * dp[i - j])
    
    return dp[n]

# 示例调用
print(integerBreak(10))  # 输出应该是 36
