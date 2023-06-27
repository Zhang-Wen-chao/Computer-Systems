// 139. Word Break
// https://leetcode.com/problems/word-break/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    vector<string> wordDict = {"leet", "code"};
    string str = "leetcode";
    cout<<s.wordBreak(str, wordDict)<<endl;
    return 0;
}