// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m-1][n-1];
}

int main() {
    std::vector<std::pair<int, int>> testCases = {{3, 7}, {3, 2}};
    for (auto& testCase: testCases) {
        std::cout << "Number of unique paths: " << uniquePaths(testCase.first, testCase.second) << std::endl;
    }
    
    return 0;
}
