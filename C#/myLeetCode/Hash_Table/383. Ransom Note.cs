// 383. Ransom Note
// https://leetcode.com/problems/ransom-note/

#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> charCount;

        // 统计 magazine 中每个字符的出现次数
        for (char ch : magazine) {
            charCount[ch]++;
        }

        // 检查 ransomNote 中的字符是否在 charCount 中，并递减对应的出现次数
        for (char ch : ransomNote) {
            if (charCount[ch] == 0) {
                return false;
            }
            charCount[ch]--;
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