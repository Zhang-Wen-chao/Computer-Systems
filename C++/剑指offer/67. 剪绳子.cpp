#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cutRope(int length) {
        if (length < 2) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;

        // dp[i] represents the maximum product of cutting a rope of length i
        vector<int> dp(length + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3; // for lengths greater than 3, we treat 3 as a piece rather than a whole

        for (int i = 4; i <= length; ++i) {
            int max_val = 0;
            for (int j = 1; j <= i / 2; ++j) {
                max_val = max(max_val, dp[j] * dp[i - j]);
            }
            dp[i] = max_val;
        }

        return dp[length];
    }
};

int main() {
    Solution solution;
    int ropeLength = 10; // Example length
    int maxProduct = solution.cutRope(ropeLength);
    cout << "The maximum product for a rope of length " << ropeLength << " is " << maxProduct << "." << endl;
    return 0;
}
