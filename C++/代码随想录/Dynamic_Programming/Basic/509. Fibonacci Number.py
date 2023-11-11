def fib(n):
    if n <= 1:
        return n

    dp = [0] * (n + 1)
    dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

# 测试用例
print(fib(0))  # 输出应该是 0
print(fib(1))  # 输出应该是 1
print(fib(2))  # 输出应该是 1
print(fib(3))  # 输出应该是 2
print(fib(4))  # 输出应该是 3
print(fib(5))  # 输出应该是 5
