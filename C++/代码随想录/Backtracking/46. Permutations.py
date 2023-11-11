def permute(nums):
    def backtrack(start, end):
        if start == end:
            result.append(nums[:])
            return
        for i in range(start, end):
            nums[start], nums[i] = nums[i], nums[start]  # 交换
            backtrack(start + 1, end)
            nums[start], nums[i] = nums[i], nums[start]  # 恢复

    result = []
    backtrack(0, len(nums))
    return result

# 测试用例
nums = [1, 2, 3]
print(permute(nums))
