from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k

# Create an instance of the Solution class
sol = Solution()

# Test case 1: Remove an element that appears multiple times
nums1 = [3, 2, 2, 3]
val1 = 3
new_length1 = sol.removeElement(nums1, val1)
print("New length:", new_length1, "Modified array:", nums1[:new_length1])  # Output: New length: 2 Modified array: [2, 2]

# Test case 2: Remove an element that does not appear
nums2 = [1, 2, 3, 4, 5]
val2 = 6
new_length2 = sol.removeElement(nums2, val2)
print("New length:", new_length2, "Modified array:", nums2[:new_length2])  # Output: New length: 5 Modified array: [1, 2, 3, 4, 5]

# Test case 3: Remove an element that appears once
nums3 = [1, 2, 3, 4, 5]
val3 = 3
new_length3 = sol.removeElement(nums3, val3)
print("New length:", new_length3, "Modified array:", nums3[:new_length3])  # Output: New length: 4 Modified array: [1, 2, 4, 5]
