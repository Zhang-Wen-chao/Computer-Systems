// 474. Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int findMaxForm(std::vector<std::string>& strs, int m, int n) {
    int size = strs.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    
    for (int i = 0; i < size; i++) {
        int zeros = 0;
        int ones = 0;
        
        for (char c : strs[i]) {
            if (c == '0') {
                zeros++;
            } else if (c == '1') {
                ones++;
            }
        }
        
        for (int j = m; j >= zeros; j--) {
            for (int k = n; k >= ones; k--) {
                dp[j][k] = std::max(dp[j][k], dp[j - zeros][k - ones] + 1);
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    std::vector<std::vector<std::string>> testCases = {
        {"10", "0001", "111001", "1", "0"},
        {"10", "0", "1"},
        {"11111", "100", "1101", "1101", "1100"},
    };

    std::vector<int> mValues = {5, 1, 9};
    std::vector<int> nValues = {3, 1, 3};

    for (int i = 0; i < testCases.size(); i++) {
        int result = findMaxForm(testCases[i], mValues[i], nValues[i]);
        std::cout << "For the strings: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << "\"" << testCases[i][j] << "\"";
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the maximum number of strings that can be formed with " << mValues[i] << " 0's and " << nValues[i] << " 1's is " << result << "." << std::endl;
    }

    return 0;
}