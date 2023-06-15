# 977. Squares of a Sorted Array
# https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution:
    def sortedSquares_Double_pointer(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [0] * n
        left, right = 0, n - 1
        pos = n - 1
        while left <= right:
            if nums[left] * nums[left] > nums[right] * nums[right]:
                ans[pos] = nums[left] * nums[left]
                left += 1
            else:
                ans[pos] = nums[right] * nums[right]
                right -= 1
            pos -= 1
        return ans

def main():
    sol = Solution()
    nums = [-4, -1, 0, 3, 10]
    ans = sol.sortedSquares_Double_pointer(nums)
    print(*ans)
    
if __name__ == "__main__":
    main()


