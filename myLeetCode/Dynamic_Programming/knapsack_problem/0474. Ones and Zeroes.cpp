// 474. Ones and Zeroes
// https://leetcode.com/problems/ones-and-zeroes/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(string str:strs)
        {
            int zero=0;
            int one=0;
            for(char c:str)
            {
                if(c=='0')
                    zero++;
                else
                    one++;
            }
            for(int i=m;i>=zero;i--)
                for(int j=n;j>=one;j--)
                    dp[i][j]=max(dp[i][j],dp[i-zero][j-one]+1);
        }
        return dp[m][n];
    }
};

int main() {
    Solution s;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    cout << s.findMaxForm(strs, m, n) << endl; // output: 4
    return 0;
}
