// 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/

#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<int> minfreq(26, INT_MAX);
        std::vector<int> freq(26);
        for (const std::string& word: words) {
            std::fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minfreq[i] = std::min(minfreq[i], freq[i]);
            }
        }

        std::vector<std::string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minfreq[i]; ++j) {
                ans.emplace_back(1, i + 'a');// emplace_back(n,m)尾端插入n个m
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words = {"bella","label","roller"};
    std::vector<std::string> ans = sol.commonChars(words);
    for (auto& str: ans) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}