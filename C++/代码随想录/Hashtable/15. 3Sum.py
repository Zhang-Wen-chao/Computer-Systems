from typing import List

def threeSum(nums: List[int]) -> List[List[int]]:
    nums.sort()
    result = []
    
    for i in range(len(nums) - 2):
        left, right = i + 1, len(nums) - 1
        
        if nums[i] > 0:  # Early exit condition
            return result
        if i > 0 and nums[i] == nums[i - 1]:  # Skip duplicates
            continue

        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            if sum > 0:
                right -= 1
            elif sum < 0:
                left += 1
            else:
                result.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left + 1]:  # Skip duplicates
                    left += 1
                while left < right and nums[right] == nums[right - 1]:  # Skip duplicates
                    right -= 1
                left += 1
                right -= 1
    return result

nums = [-1, 0, 1, 2, -1, -4]
print(threeSum(nums))  # 输出: [[-1, -1, 2], [-1, 0, 1]]
