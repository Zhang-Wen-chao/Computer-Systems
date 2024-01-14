// 1002. Find Common Characters
// https://leetcode.com/problems/find-common-characters/

#include <iostream>
#include <vector>
#include <string>
#include <climits>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& words) {
        std::vector<int> minFreq(26, INT_MAX);
        std::vector<int> freq(26);

        for (const std::string& word: words) {
            std::fill(freq.begin(), freq.end(), 0);
            for (char ch: word) {
                ++freq[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                minFreq[i] = std::min(minFreq[i], freq[i]);
            }
        }

        std::vector<std::string> result;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < minFreq[i]; ++j) {
                result.push_back(std::string(1, i + 'a'));
            }
        }
        return result;
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