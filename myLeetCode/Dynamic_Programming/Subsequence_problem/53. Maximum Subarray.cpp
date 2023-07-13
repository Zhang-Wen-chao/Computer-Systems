// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    int maxSum = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
        maxSum = std::max(maxSum, dp[i]);
    }

    return maxSum;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},
        {1},
        {5, 4, -1, 7, 8}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> nums = testCases[i];

        int maxSubArrSum = maxSubArray(nums);

        std::cout << "Test case " << (i + 1) << ": ";
        std::cout << "The maximum sum of the subarray is: " << maxSubArrSum << std::endl;
    }

    return 0;
}