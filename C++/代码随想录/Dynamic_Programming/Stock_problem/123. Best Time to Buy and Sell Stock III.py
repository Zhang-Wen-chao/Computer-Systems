def maxProfit(prices):
    if not prices:
        return 0

    first_buy, first_sell = float('-inf'), 0
    second_buy, second_sell = float('-inf'), 0

    for price in prices:
        first_buy = max(first_buy, -price)
        first_sell = max(first_sell, first_buy + price)
        second_buy = max(second_buy, first_sell - price)
        second_sell = max(second_sell, second_buy + price)

    return second_sell

# 测试用例
print(maxProfit([3,3,5,0,0,3,1,4]))  # 输出应该是 6
print(maxProfit([1,2,3,4,5]))        # 输出应该是 4
print(maxProfit([7,6,4,3,1]))        # 输出应该是 0
