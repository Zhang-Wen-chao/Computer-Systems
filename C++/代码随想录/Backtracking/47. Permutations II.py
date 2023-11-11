def permuteUnique(nums):
    def backtrack(start, end):
        if start == end:
            result.append(nums[:])
            return
        seen = set()
        for i in range(start, end):
            if nums[i] not in seen:
                seen.add(nums[i])
                nums[start], nums[i] = nums[i], nums[start]  # 交换
                backtrack(start + 1, end)
                nums[start], nums[i] = nums[i], nums[start]  # 恢复

    result = []
    nums.sort()  # 排序以便于处理重复元素
    backtrack(0, len(nums))
    return result

# 测试用例
nums = [1, 1, 2]
print(permuteUnique(nums))
