def maxSubArray(nums):
    n = len(nums)
    if n == 0:
        return 0

    max_sum = current_sum = nums[0]
    for i in range(1, n):
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)

    return max_sum

# 测试用例
print(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))  # 输出应该是 6
