// 70. Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    int n = 3;
    cout<<s.climbStairs(n)<<endl;
    return 0;
}