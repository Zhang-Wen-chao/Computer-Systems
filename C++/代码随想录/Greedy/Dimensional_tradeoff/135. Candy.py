def candy(ratings):
    n = len(ratings)
    candies = [1] * n

    # 从左到右遍历，确保每个孩子比他左边评分低的孩子得到更多的糖果
    for i in range(1, n):
        if ratings[i] > ratings[i - 1]:
            candies[i] = candies[i - 1] + 1

    # 从右到左遍历，确保每个孩子比他右边评分低的孩子得到更多的糖果
    for i in range(n - 2, -1, -1):
        if ratings[i] > ratings[i + 1]:
            candies[i] = max(candies[i], candies[i + 1] + 1)

    return sum(candies)

# 测试用例
print(candy([1, 0, 2]))  # 应该输出 5
print(candy([1, 2, 2]))  # 应该输出 4
