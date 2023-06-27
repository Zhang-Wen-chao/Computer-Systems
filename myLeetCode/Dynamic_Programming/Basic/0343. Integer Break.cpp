// 343. Integer Break
// https://leetcode.com/problems/integer-break/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main() {
    vector<int> testCases = {2, 10, 5};
    Solution obj;
    for (auto& testCase: testCases) {
        cout << "For n = " << testCase << ", the maximum product is: " << obj.integerBreak(testCase) << endl;
    }
    return 0;
}