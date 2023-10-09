// 343. Integer Break
// https://leetcode.com/problems/integer-break/

#include <iostream>
#include <vector>

int integerBreak(int n) {
    std::vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
        }
    }

    return dp[n];
}

int main() {
    std::vector<int> testCases = {2, 10, 5};
    for (auto& testCase: testCases) {
        std::cout << "For n = " << testCase << ", the maximum product is: " << integerBreak(testCase) << std::endl;
    }
    
    return 0;
}