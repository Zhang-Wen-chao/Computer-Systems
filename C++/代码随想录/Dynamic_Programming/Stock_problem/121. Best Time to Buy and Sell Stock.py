def maxProfit(prices):
    if not prices:
        return 0

    min_price = prices[0]
    max_profit = 0

    for price in prices:
        min_price = min(min_price, price)
        profit = price - min_price
        max_profit = max(max_profit, profit)

    return max_profit

# 测试用例
print(maxProfit([7, 1, 5, 3, 6, 4]))  # 输出应该是 5
print(maxProfit([7, 6, 4, 3, 1]))  # 输出应该是 0
