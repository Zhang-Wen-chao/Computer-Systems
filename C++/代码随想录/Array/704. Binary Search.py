from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left <= right:
            mid = left + (right - left) // 2

            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return -1

# Create an instance of the Solution class
sol = Solution()

# Test cases
print(sol.search([-1,0,3,5,9,12], 9))  # Output: 4
print(sol.search([-1,0,3,5,9,12], 2))  # Output: -1
print(sol.search([5], 5))              # Output: 0