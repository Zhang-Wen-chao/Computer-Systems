// 96. Unique Binary Search Trees
// https://leetcode.com/problems/unique-binary-search-trees/

#include <iostream>
#include <vector>

int numTrees(int n) {
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int main() {
    std::vector<int> testCases = {1, 3, 5, 10};
    for (auto& testCase: testCases) {
        std::cout << "For n = " << testCase << ", the number of unique BSTs is: " << numTrees(testCase) << std::endl;
    }
    
    return 0;
}