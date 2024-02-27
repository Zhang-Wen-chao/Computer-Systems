def maxSubArray(nums):
    if not nums:
        return 0

    max_sum = current_sum = nums[0]
    for num in nums[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)

    return max_sum

# 测试用例
print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))  # 应该输出 6
print(maxSubArray([1]))                      # 应该输出 1
print(maxSubArray([5,4,-1,7,8]))             # 应该输出 23
