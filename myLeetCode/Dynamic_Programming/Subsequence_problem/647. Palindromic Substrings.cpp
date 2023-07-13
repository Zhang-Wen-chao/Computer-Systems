// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

#include <iostream>
#include <string>
#include <vector>

int countSubstrings(std::string s) {
    int n = s.length();
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    int count = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
}

int main() {
    std::vector<std::string> testCases = {
        "abc",
        "aaa",
    };

    for (int i = 0; i < testCases.size(); i++) {
        std::string s = testCases[i];

        int count = countSubstrings(s);

        std::cout << "Number of palindromic substrings for test case " << (i + 1) << ": ";
        std::cout << count << std::endl;
    }

    return 0;
}