def wiggleMaxLength(nums):
    if len(nums) < 2:
        return len(nums)

    up = down = 1
    for i in range(1, len(nums)):
        if nums[i] > nums[i - 1]:
            up = down + 1
        elif nums[i] < nums[i - 1]:
            down = up + 1

    return max(up, down)

# 测试用例
print(wiggleMaxLength([1,7,4,9,2,5]))  # 应该输出 6
print(wiggleMaxLength([1,17,5,10,13,15,10,5,16,8]))  # 应该输出 7
print(wiggleMaxLength([1,2,3,4,5,6,7,8,9]))  # 应该输出 2
