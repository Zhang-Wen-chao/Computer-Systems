// 139. Word Break
// https://leetcode.com/problems/word-break/

#include <iostream>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
    int n = s.length();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

int main() {
    std::vector<std::string> testCases = {
        "leetcode",
        "applepenapple",
        "catsandog"
    };
    std::vector<std::vector<std::string>> wordDicts = {
        {"leet", "code"},
        {"apple", "pen"},
        {"cats", "dog", "sand", "and", "cat"}
    };

    for (int i = 0; i < testCases.size(); i++) {
        bool result = wordBreak(testCases[i], wordDicts[i]);

        std::cout << "For the string " << testCases[i] << ", ";
        if (result) {
            std::cout << "it can be segmented into a space-separated sequence of dictionary words.";
        } else {
            std::cout << "it cannot be segmented into a space-separated sequence of dictionary words.";
        }
        std::cout << std::endl;
    }

    return 0;
}