// 279. Perfect Squares
// https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            for(int j=1; j*j<=i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    int n = 13;
    cout << s.numSquares(n) << endl;
    return 0;
}