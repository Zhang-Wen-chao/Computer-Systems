// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <iostream>
#include <string>
#include <vector>

int longestPalindromeSubseq(std::string s) {
    int n = s.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    std::vector<std::string> testCases = {
        "bbbab",
        "cbbd",
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::string s = testCases[i];

        int length = longestPalindromeSubseq(s);

        std::cout << "Length of the longest palindromic subsequence for test case " << (i + 1) << ": ";
        std::cout << length << std::endl;
    }

    return 0;
}