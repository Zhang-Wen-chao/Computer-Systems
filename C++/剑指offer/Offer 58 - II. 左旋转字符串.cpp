// 剑指 Offer 58 - II. 左旋转字符串
// https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/

#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string reverseLeftWords(std::string str, int n) {
        std::rotate(str.begin(), str.begin() + n, str.end());
        return str;
    }
};

int main() {
    Solution sol;
    std::string str = "abcdefg";
    int n = 2;
    std::cout << sol.reverseLeftWords(str, n) << std::endl;
    return 0;
}
