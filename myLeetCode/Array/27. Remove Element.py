# 27. Remove Element
# https://leetcode.com/problems/remove-element/

class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        left = 0
        for right in range(len(nums)):
            if nums[right] != val:
                nums[left] = nums[right]
                left += 1
        return left

def main():
    sol = Solution()
    nums = [0, 1, 2, 2, 3, 0, 4, 2]
    target = 2
    ans = sol.removeElement(nums, target)

    print(ans)
    for i in range(ans):
        print(nums[i], end=" ")

if __name__ == "__main__":
    main()