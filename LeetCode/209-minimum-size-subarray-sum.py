from typing import List

def minSubArrayLen(target: int, nums: List[int]) -> int:
    n = len(nums)
    left = 0
    sum = 0
    min_length = float('inf')
    
    for right in range(n):
        sum += nums[right]
        while sum >= target:
            min_length = min(min_length, right - left + 1)
            sum -= nums[left]
            left += 1
    
    return min_length if min_length != float('inf') else 0

# 示例
target = 7
nums = [2, 3, 1, 2, 4, 3]
result = minSubArrayLen(target, nums)
print(f"长度最小的子数组的长度是: {result}")
