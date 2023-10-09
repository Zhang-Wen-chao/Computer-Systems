// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>
#include <limits>

int numSquares(int n) {
    std::vector<int> dp(n + 1, std::numeric_limits<int>::max());
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = std::min(dp[i], dp[i - j*j] + 1);
        }
    }
    
    return dp[n];
}

int main() {
    std::vector<int> testCases = {12, 13, 27};

    for (int i = 0; i < testCases.size(); i++) {
        int result = numSquares(testCases[i]);

        std::cout << "For the number " << testCases[i]
                  << ", the minimum number of perfect squares needed is " << result << "." << std::endl;
    }

    return 0;
}