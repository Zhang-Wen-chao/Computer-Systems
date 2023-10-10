// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }
        std::vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::string str = "anagram";
    std::cout<< s.isAnagram(str, "nagaram") << std::endl;
    return 0;
}