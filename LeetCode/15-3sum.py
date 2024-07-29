def threeSum(nums):
    nums.sort()
    result = []
    n = len(nums)
    
    for i in range(n - 2):
        # 如果当前数和前一个数相同，跳过，避免重复结果
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        
        left, right = i + 1, n - 1
        while left < right:
            total = nums[i] + nums[left] + nums[right]
            if total == 0:
                result.append([nums[i], nums[left], nums[right]])
                # 跳过相同的元素，避免重复结果
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                left += 1
                right -= 1
            elif total < 0:
                left += 1
            else:
                right -= 1
    
    return result

nums = [-1, 0, 1, 2, -1, -4]
print(threeSum(nums))  # 输出: [[-1, -1, 2], [-1, 0, 1]]
