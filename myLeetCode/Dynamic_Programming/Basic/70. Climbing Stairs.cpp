// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>

int climbStairs(int n) {
    if (n < 0) return -1;
    std::vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main(){
    std::vector<int> testCases = {2, 3, 4};
    for (auto& testCase: testCases) {
        std::cout << "For n = " << testCase << ", the number of distinct ways can climb to the top is: " << climbStairs(testCase) << std::endl;
    }

    return 0;
}