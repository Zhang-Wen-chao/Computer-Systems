from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return []
        if k == 0:
            return []

        deq = deque()
        max_numbers = []

        for i in range(len(nums)):
            # 保持 deque 的大小不超过 k
            while deq and deq[0] < i - k + 1:
                deq.popleft()
            # 移除比当前元素小的所有元素
            while deq and nums[i] > nums[deq[-1]]:
                deq.pop()
            deq.append(i)

            # 从第 k - 1 个元素开始记录最大值
            if i >= k - 1:
                max_numbers.append(nums[deq[0]])

        return max_numbers

# Test case
sol = Solution()
print(sol.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3))  # [3,3,5,5,6,7]
