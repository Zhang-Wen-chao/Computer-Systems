from typing import List

class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        count = 0
        sum_map = {}
        for n1 in nums1:
            for n2 in nums2:
                sum_map[n1 + n2] = sum_map.get(n1 + n2, 0) + 1
        for n3 in nums3:
            for n4 in nums4:
                count += sum_map.get(-1 * (n3 + n4), 0)
        return count

sol = Solution()

# 测试用例
print(sol.fourSumCount([1, 2], [-2, -1], [-1, 2], [0, 2]))  # 应该输出 2
