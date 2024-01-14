def findLengthOfLCIS(nums):
    if not nums:
        return 0

    maxLength = 1
    currentLength = 1

    for i in range(1, len(nums)):
        if nums[i] > nums[i - 1]:
            currentLength += 1
            maxLength = max(maxLength, currentLength)
        else:
            currentLength = 1

    return maxLength

# 测试用例
print(findLengthOfLCIS([1, 3, 5, 4, 7]))  # 输出应该是 3
print(findLengthOfLCIS([2, 2, 2, 2, 2]))  # 输出应该是 1
