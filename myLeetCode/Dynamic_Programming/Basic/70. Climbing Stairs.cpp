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
    std::cout << climbStairs(2) << std::endl; // print the output: 2

    std::cout << climbStairs(3) << std::endl; // print the output: 3

    std::cout << climbStairs(4) << std::endl; // print the output: 5

    return 0;
}