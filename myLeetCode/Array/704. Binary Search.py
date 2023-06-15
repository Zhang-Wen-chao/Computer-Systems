# 704. Binary Search
# https://leetcode.com/problems/binary-search/

class Solution:
    def search(self, nums: list[int], target: int) -> int:
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

def main():
    sol = Solution()
    nums = [-1, 0, 3, 5, 9, 12]
    target = 12
    print(sol.search(nums, target))

if __name__ == "__main__":
    main()
