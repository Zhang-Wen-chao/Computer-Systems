from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        return sorted(x*x for x in nums)

sol = Solution()

# Test cases
print(sol.sortedSquares([-4,-1,0,3,10]))  # Output: [0,1,9,16,100]
print(sol.sortedSquares([-7,-3,2,3,11]))  # Output: [4,9,9,49,121]
