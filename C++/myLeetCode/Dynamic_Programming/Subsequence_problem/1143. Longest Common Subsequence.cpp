// 1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

int longestCommonSubsequence(std::string text1, std::string text2) {
    int m = text1.length();
    int n = text2.length();

    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"abcde", "ace"},
        {"abc", "abc"},
        {"abc", "def"}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::string text1 = testCases[i].first;
        std::string text2 = testCases[i].second;

        int maxLength = longestCommonSubsequence(text1, text2);

        std::cout << "Test case " << (i + 1) << ": ";
        std::cout << "The length of the longest common subsequence is: " << maxLength << std::endl;
    }

    return 0;
}