// 583. Delete Operation for Two Strings
// https://leetcode.com/problems/delete-operation-for-two-strings/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string word1, word2;
    cin >> word1 >> word2;
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}



// 这个解决方案使用了动态规划的思想，用一个二维数组dp来存储子问题的解。
// dp[i][j]表示使word1的前i个字符和word2的前j个字符相同所需的最小删除操作数。状态转移方程是：

// - 如果i==0或者j==0，那么dp[i][j]=i+j
// - 如果word1[i-1]==word2[j-1]，那么dp[i][j]=dp[i-1][j-1]
// - 如果word1[i-1]!=word2[j-1]，那么dp[i][j]=min(dp[i-1][j],dp[i][j-1])+

