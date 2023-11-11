def subsetsWithDup(nums):
    def backtrack(start, path):
        result.append(path[:])
        for i in range(start, len(nums)):
            # 跳过重复元素
            if i > start and nums[i] == nums[i - 1]:
                continue
            path.append(nums[i])
            backtrack(i + 1, path)
            path.pop()

    result = []
    nums.sort()  # 对数组排序以方便去重
    backtrack(0, [])
    return result

# 测试用例
nums = [1, 2, 2]
print(subsetsWithDup(nums))
