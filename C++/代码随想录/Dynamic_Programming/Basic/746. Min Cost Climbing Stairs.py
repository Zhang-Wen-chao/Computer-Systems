def minCostClimbingStairs(cost):
    n = len(cost)
    if n == 0 or n == 1:
        return 0

    min_cost = [0] * (n + 1)
    min_cost[1] = cost[0]

    for i in range(2, n + 1):
        min_cost[i] = min(min_cost[i - 1], min_cost[i - 2]) + (cost[i - 1] if i < n else 0)

    return min_cost[n]

# 测试用例
print(minCostClimbingStairs([10, 15, 20]))  # 输出应该是 15
print(minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))  # 输出应该是 6
