// 718. Maximum Length of Repeated Subarray
// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

#include <iostream>
#include <vector>
#include <algorithm>

int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = std::max(maxLength, dp[i][j]);
            }
        }
    }

    return maxLength;
}

int main() {
    std::vector<std::vector<std::vector<int>>> testCases = {
        {{1, 2, 3, 2, 1}, {3, 2, 1, 4, 7}},
        {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> nums1 = testCases[i][0];
        std::vector<int> nums2 = testCases[i][1];

        int maxLength = findLength(nums1, nums2);

        std::cout << "Test case " << (i + 1) << ": ";
        std::cout << "The maximum length of the repeated subarray is: " << maxLength << std::endl;
    }

    return 0;
}