def maxProfit(prices, fee):
    n = len(prices)
    if n <= 1:
        return 0

    hold = [0] * n
    not_hold = [0] * n

    hold[0] = -prices[0] - fee
    for i in range(1, n):
        hold[i] = max(hold[i - 1], not_hold[i - 1] - prices[i] - fee)
        not_hold[i] = max(not_hold[i - 1], hold[i - 1] + prices[i])

    return not_hold[-1]

# 测试用例
print(maxProfit([1, 3, 2, 8, 4, 9], 2))  # 输出应该是 8
