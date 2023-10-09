// 674. Longest Continuous Increasing Subsequence
// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <iostream>
#include <vector>

int findLengthOfLCIS(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        }
        maxLen = std::max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 3, 5, 4, 7},
        {2, 2, 2, 2, 2},
        {1, 3, 5, 7},
        {1, 3, 5, 4, 2, 3, 4, 5}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int result = findLengthOfLCIS(testCases[i]);

        std::cout << "For the sequence: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the length of the longest increasing subsequence is " << result << "." << std::endl;
    }

    return 0;
}