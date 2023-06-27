// 72. Edit Distance
// https://leetcode.com/problems/edit-distance/

// include header files
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    // create two sample strings
    string s1 = "sunday";
    string s2 = "saturday";
    
    // print the input strings
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    
    Solution s;
    int result = s.minDistance(s1, s2);
    
    // print the output result
    cout << "Minimum edit distance: " << result << endl;
    
}
