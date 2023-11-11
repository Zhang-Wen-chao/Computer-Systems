def maxProfit(prices):
    if not prices:
        return 0

    n = len(prices)
    hold = [0] * n
    not_hold = [0] * n

    hold[0] = -prices[0]
    for i in range(1, n):
        hold[i] = max(hold[i - 1], (not_hold[i - 2] if i > 1 else 0) - prices[i])
        not_hold[i] = max(not_hold[i - 1], hold[i - 1] + prices[i])

    return not_hold[-1]

# 测试用例
print(maxProfit([1, 2, 3, 0, 2]))  # 输出应该是 3
