// 剑指 Offer 58 - II. 左旋转字符串
// https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) {
        std::rotate(s.begin(), s.begin() + n, s.end());
        return s;
    }
};

// class Solution {
// public:
//     std::string reverseLeftWords(std::string s, int n) {
//         reverse(s.begin(), s.begin() + n);
//         reverse(s.begin() + n, s.end());
//         reverse(s.begin(), s.end());
//         return s;
//     }
// };

int main() {
    Solution sol;
    std::string s = "abcdefg";
    int n = 2;
    std::cout << sol.reverseLeftWords(s, n) << std::endl;
    return 0;
}
