// 392. Is Subsequence
// https://leetcode.com/problems/is-subsequence/description/

#include <iostream>
#include <string>
#include <vector>

bool isSubsequence(std::string s, std::string t) {
    int sLen = s.length();
    int tLen = t.length();

    std::vector<std::vector<bool>> dp(sLen + 1, std::vector<bool>(tLen + 1, false));

    for (int j = 0; j <= tLen; j++) {
        dp[0][j] = true;
    }

    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= tLen; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[sLen][tLen];
}

int main() {
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"abc", "ahbgdc"},
        {"axc", "ahbgdc"}
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::string s = testCases[i].first;
        std::string t = testCases[i].second;

        bool isSubSeq = isSubsequence(s, t);

        std::cout << "Is s" << (i + 1) << " a subsequence of t" << (i + 1) << "? ";
        std::cout << (isSubSeq ? "Yes" : "No") << std::endl;
    }

    return 0;
}