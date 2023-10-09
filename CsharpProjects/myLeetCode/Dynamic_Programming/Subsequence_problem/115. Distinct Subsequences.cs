// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/

#include <iostream>
#include <string>
#include <vector>

int numDistinct(std::string s, std::string t) {
    int sLen = s.length();
    int tLen = t.length();

    std::vector<std::vector<long long>> dp(sLen + 1, std::vector<long long>(tLen + 1, 0));

    for (int i = 0; i <= sLen; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= tLen; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[sLen][tLen];
}

int main() {
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"rabbbit", "rabbit"},
        {"babgbag", "bag"}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::string s = testCases[i].first;
        std::string t = testCases[i].second;

        int num = numDistinct(s, t);

        std::cout << "Number of distinct subsequences for test case " << (i + 1) << ": ";
        std::cout << num << std::endl;
    }

    return 0;
}