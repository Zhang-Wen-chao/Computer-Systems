from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        result = []

        for i in range(len(nums)):
            # 避免重复的三元组
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left, right = i + 1, len(nums) - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total < 0:
                    left += 1
                elif total > 0:
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    # 跳过重复的元素
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1
                    left += 1
                    right -= 1
        return result

sol = Solution()

# 测试用例
print(sol.threeSum([-1, 0, 1, 2, -1, -4]))  # 应该输出 [[-1, -1, 2], [-1, 0, 1]]
print(sol.threeSum([]))  # 应该输出 []
print(sol.threeSum([0]))  # 应该输出 []
