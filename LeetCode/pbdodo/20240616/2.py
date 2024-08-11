# 多多君喜欢到炸鸡店吃汉堡。 未来N天，多多军想好了要吃的汉堡，且已知第i天的汉堡价格为Pi。 
# 多多炸鸡店为了回馈老客户，吃掉汉堡后可以获得与价格同等数量的汉堡币，且使用100个汉堡币可以兑换一张免单券，可以免费吃任意汉堡。 
# 多多君希望你能帮助他找到一个最省钱的吃汉堡计划：未来N天每天吃一个汉堡的情况下，最少要花多少钱？ 
# 输入：第一行，一个整数T,表示测试用的组数。
# 对于每组测试用例：第一行，一个整数N,表示未来汉堡得天数。接下来N行，每行一个整数Pi,表示第i天多多君要购买的汉堡价格。 
# 输出：对于每组测试用例，输出一行：一个整数，表示吃完所有汉堡的最小花费。
def min_cost_to_eat_burgers(t, test_cases):
    results = []

    for case in test_cases:
        n = case[0]
        prices = case[1]

        # 初始化dp数组，大小为n+1，初始值为无穷大
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        points = [0] * (n + 1)

        for i in range(1, n + 1):
            price = prices[i - 1]

            # 第一种情况：直接购买汉堡
            dp[i] = dp[i - 1] + price
            points[i] = points[i - 1] + price

            # 第二种情况：如果汉堡币足够，可以用免单券
            if points[i - 1] >= 100:
                for j in range(i - 1, -1, -1):
                    if points[j] >= 100:
                        dp[i] = min(dp[i], dp[j] + price)
                        points[i] = points[j] + price - 100
                        break

        results.append(dp[n])

    return results

# 输入处理
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    test_cases = []
    
    for _ in range(t):
        n = int(data[index])
        index += 1
        prices = []
        for _ in range(n):
            prices.append(int(data[index]))
            index += 1
        test_cases.append((n, prices))
    
    results = min_cost_to_eat_burgers(t, test_cases)
    for result in results:
        print(result)

# 调用主函数
if __name__ == "__main__":
    main()
