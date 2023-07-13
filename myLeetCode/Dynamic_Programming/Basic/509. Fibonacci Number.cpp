// LeetCode 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/


// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        // base cases
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // create an array to store the fibonacci numbers
        vector<int> dp(n + 1);
        
        // initialize the first two numbers
        dp[0] = 0;
        dp[1] = 1;
        
        // iterate from the third number to the nth number
        for (int i = 2; i <= n; i++) {
            // calculate the current number by adding the previous two numbers
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        // return the nth number
        return dp[n];
    }
};

int main() {
    // test case: n = 4
    int n = 4;
    
    Solution solution;
    int result = solution.fib(n);
    
    // print the output: 3
    cout << result << endl;
    
    return 0;
}