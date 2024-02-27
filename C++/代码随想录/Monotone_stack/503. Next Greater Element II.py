def nextGreaterElements(nums):
    n = len(nums)
    result = [-1] * n
    stack = []

    for i in range(2 * n):
        while stack and nums[stack[-1]] < nums[i % n]:
            result[stack.pop()] = nums[i % n]
        if i < n:
            stack.append(i)

    return result

# 测试用例
print(nextGreaterElements([1, 2, 1]))  # 应输出 [2, -1, 2]
print(nextGreaterElements([1, 2, 3, 4, 3]))  # 应输出 [2, 3, 4, -1, 4]
