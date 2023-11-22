def twoSum(nums, target):
    num_map = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i
    return []

# 测试用例
print(twoSum([2, 7, 11, 15], 9))  # 应该输出 [0, 1]
print(twoSum([3, 2, 4], 6))  # 应该输出 [1, 2]
print(twoSum([3, 3], 6))  # 应该输出 [0, 1]
