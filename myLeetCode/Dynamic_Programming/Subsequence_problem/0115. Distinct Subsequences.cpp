// 115. Distinct Subsequences
// https://leetcode.com/problems/distinct-subsequences/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string s, t;
    cin >> s >> t;
    cout << sol.numDistinct(s, t) << endl;
    return 0;
}

