// 647. Palindromic Substrings
// https://leetcode.com/problems/palindromic-substrings/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int result = 0;
        for (int i = n - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // 情况一 和 情况二
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.countSubstrings(s) << endl;
    return 0;
}



// 这个解决方案使用了动态规划的思想，用一个二维数组dp来存储子问题的解。dp[i][j]表示s的第i个字符到第j个字符之间是否是回文串。状态转移方程是：

// - 如果i==j，那么dp[i][j]=true，并且答案加一
// - 如果s[i]==s[j]并且i+1==j，那么dp[i][j]=true，并且答案加一
// - 如果s[i]==s[j]并且dp[i+1][j-1]==true，那么dp[i][j]=true，并且答案加一

// 最后返回答案。