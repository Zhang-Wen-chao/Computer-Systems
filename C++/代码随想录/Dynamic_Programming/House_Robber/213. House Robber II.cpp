// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();

        // 不偷取第一间房子的最大金额
        int max1 = robRange(nums, 1, n - 1);

        // 不偷取最后一间房子的最大金额
        int max2 = robRange(nums, 0, n - 2);

        return std::max(max1, max2);
    }

private:
    int robRange(std::vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return nums[start];
        } else if (n == 2) {
            return std::max(nums[start], nums[start + 1]);
        }

        std::vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = std::max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            dp[i] = std::max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> testCases = {
        {2, 3, 2},
        {1, 2, 3, 1},
        {1, 2, 3}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::cout << "For the test case " << i + 1 << ", the maximum amount of money that can be robbed is " << Solution().rob(testCases[i]) << "." << std::endl;
    }

    return 0;
}