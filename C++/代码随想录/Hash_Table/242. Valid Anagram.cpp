// 242. Valid Anagram
// https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) return false;

        // 使用一个数组来计数，因为题目中提到只包含小写字母
        std::vector<int> counter(26, 0);

        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'a']++;  // 对于字符串s中的字符，增加计数
            counter[t[i] - 'a']--;  // 对于字符串t中的字符，减少计数
        }

        // 检查计数器中的所有值是否都是0
        for (int count : counter) {
            if (count != 0) return false;
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