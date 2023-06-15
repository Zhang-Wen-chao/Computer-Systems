# 209. Minimum Size Subarray Sum
# https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        result = float('inf')
        left = 0
        sub_length = 0
        current_sum = 0
        n = len(nums)

        for right in range(n):
            current_sum += nums[right]

            while current_sum >= target:
                sub_length = right - left + 1
                result = min(result, sub_length)
                current_sum -= nums[left]
                left += 1

        return result if result != float('inf') else 0


def main():
    sol = Solution()
    nums = [2, 3, 1, 2, 4, 3]
    target = 7
    ans = sol.minSubArrayLen(target, nums)
    print(ans)

if __name__ == "__main__":
    main()