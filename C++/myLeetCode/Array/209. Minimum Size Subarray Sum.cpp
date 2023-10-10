// 209. Minimum Size Subarray Sum
// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <limits>
#include <vector>

class Solution {
  public:
    int minSubArrayLen(int target, std::vector<int> &nums) {
        int result = std::numeric_limits<int>::max();
        int sum = 0;
        int left = 0;
        int subLength = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                subLength = (right - left + 1);
                result = std::min(result, subLength);
                sum -= nums[left++];
            }
        }
        return result == std::numeric_limits<int>::max() ? 0 : result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int ans = sol.minSubArrayLen(target, nums);
    std::cout << ans << std::endl;
    return 0;
}