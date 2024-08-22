# 数轴上有n个格子，标号分别从1到n，其中第i个构成的解锁时间为ai,也就是说在第ai秒之后（包括第ai秒）此格子才能到达。
# 假设小本目前位于第i个格子，则小本每秒钟可以做以下两种移动之一：
# 移动到第i+1格，前提是第i+1格已经解锁。
# 停在当前所在的格子不移动。

# 小本位于第1个格子，保证a1=0,小本想知道，他最少需要多少秒可以移动到第n个格子。


# 输入
# 2
# 5
# 0 2 4 2 4
# 4
# 0 3 5 10
# 输出
# 6
# 10

# 第一行的正整数T,代表测试数据的组数
# 接下来对于每组测试数据，包含两行。第一行一个正整数表示有n个格子。第二行n个整数，表示第i个格子解锁的时间。
# 输出T行，每行一个整数表示到达第n个格子的最短秒数。

def min_time_to_reach_end(n, a):
    dp = [float('inf')] * n
    dp[0] = 0  # 小本从第1个格子开始，所以初始时间为0

    for i in range(1, n):
        dp[i] = max(dp[i-1] + 1, a[i])
    
    return dp[-1]

def solve(num, test_cases):
    results = []
    for i in range(num):
        n, a = test_cases[i]
        result = min_time_to_reach_end(n, a)
        results.append(result)
    return results

# 获取输入
num = int(input())
test_cases = []

for _ in range(num):
    n = int(input())
    a = list(map(int, input().split()))
    test_cases.append((n, a))

# 输出结果
results = solve(num, test_cases)
for result in results:
    print(result)
