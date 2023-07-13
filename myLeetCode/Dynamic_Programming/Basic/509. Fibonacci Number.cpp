// LeetCode 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1

#include <iostream>
#include <vector>

int fib(int n) {
    if (n < 0) return -1;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

int main() {    
    std::vector<int> testCases = {2, 3, 4, 5, 6};
    for (auto& testCase: testCases) {
        std::cout << "For n = " << testCase << ", the Fibonacci number is: " << fib(testCase) << std::endl;
    }
    
    return 0;
}
