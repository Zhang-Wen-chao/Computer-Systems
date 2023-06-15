// 1035. Uncrossed Lines
// https://leetcode.com/problems/uncrossed-lines/

#include <vector>
// head files
#include <iostream>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};

// main function
int main() {
    // input
    vector<int> A = {2,5,1,2,5};
    vector<int> B = {10,5,2,1,5,2};
    
    // output
    Solution sol;
    int ans = sol.maxUncrossedLines(A,B);
    cout << ans << endl;
    

}