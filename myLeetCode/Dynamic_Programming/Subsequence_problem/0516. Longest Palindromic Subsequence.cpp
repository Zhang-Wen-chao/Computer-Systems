// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}


// 这个解决方案使用了动态规划的思想，用一个二维数组dp来存储子问题的解。dp[i][j]表示s的第i个字符到第j个字符之间的最长回文子序列的长度。状态转移方程是：

// - 如果i==j，那么dp[i][j]=1
// - 如果s[i]==s[j]，那么dp[i][j]=dp[i+1][j-1]+2
// - 如果s[i]!=s[j]，那么dp[i][j]=max(dp[i+1][j],dp[i][j-1])

// 最后返回dp[0][n-1]，其中n是s的长度。
