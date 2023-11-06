// 198. House Robber
// https://leetcode.com/problems/house-robber/

#include <iostream>
#include <vector>
#include <algorithm>

int rob(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return nums[0];
    }
    
    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
    }
    
    return dp[n-1];
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 1},
        {2, 7, 9, 3, 1},
        {1, 2, 3, 4, 5, 6}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int result = rob(testCases[i]);

        std::cout << "For the test case " << i+1 << ", the maximum amount of money that can be robbed is " << result << "." << std::endl;
    }

    return 0;
}