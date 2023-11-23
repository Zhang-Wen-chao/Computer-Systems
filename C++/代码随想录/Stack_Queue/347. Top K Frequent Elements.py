import heapq
from collections import Counter
from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = Counter(nums)
        return heapq.nlargest(k, count.keys(), key=count.get)

# Test case
sol = Solution()
print(sol.topKFrequent([1,1,1,2,2,3], 2))  # [1, 2]
print(sol.topKFrequent([1], 1))            # [1]
