def dailyTemperatures(T):
    result = [0] * len(T)
    stack = []  # 存储索引

    for i, temp in enumerate(T):
        while stack and T[stack[-1]] < temp:
            prev_index = stack.pop()
            result[prev_index] = i - prev_index
        stack.append(i)

    return result

# 测试用例
print(dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))  # 应输出 [1, 1, 4, 2, 1, 1, 0, 0]
