from collections import deque

def maxSlidingWindow(nums, k):
    if not nums:
        return []
    
    if k == 1:
        return nums
    
    # Initialize the deque and the result list
    deq = deque()
    result = []
    
    for i in range(len(nums)):
        # Remove elements that are out of the current window
        if deq and deq[0] < i - k + 1:
            deq.popleft()
        
        # Remove elements that are smaller than the current element from the end of the deque
        while deq and nums[deq[-1]] < nums[i]:
            deq.pop()
        
        # Add the current element index to the deque
        deq.append(i)
        
        # If the window has hit size k, add the maximum to the result list
        if i >= k - 1:
            result.append(nums[deq[0]])
    
    return result

nums = [1,3,-1,-3,5,3,6,7]
k = 3
print(maxSlidingWindow(nums, k))  # 输出: [3,3,5,5,6,7]

# 下面代码在 leetcode 提交超时了
# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         if len(nums) < k:
#             return []

#         result = []

#         for i in range(len(nums) - k + 1):
#             window = nums[i:i+k]
#             result.append(max(window))
        
#         return result
