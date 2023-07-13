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
    std::cout << fib(4) << std::endl; // print the output: 3

    std::cout << fib(5) << std::endl; // print the output: 5

    std::cout << fib(6) << std::endl; // print the output: 8
    
    return 0;
}