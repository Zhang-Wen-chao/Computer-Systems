// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> charCount;
        for (char c : magazine) {
            charCount[c]++;
        }

        for (char c : ransomNote) {
            if (charCount[c] > 0) {
                charCount[c]--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    std::string ransomNote, magazine;
    std::cin >> ransomNote >> magazine;
    Solution sol;
    std::cout << (sol.canConstruct(ransomNote, magazine) ? "Yes" : "No") << std::endl;
    return 0;
}