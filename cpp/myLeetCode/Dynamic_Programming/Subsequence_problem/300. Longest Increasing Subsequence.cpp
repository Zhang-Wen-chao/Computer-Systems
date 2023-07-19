// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    std::vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLen = std::max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {10, 9, 2, 5, 3, 7, 101, 18},
        {0, 1, 0, 3, 2, 3},
        {7, 7, 7, 7, 7, 7, 7},
        {1, 3, 6, 7, 9, 4, 10, 5, 6}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int result = lengthOfLIS(testCases[i]);

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