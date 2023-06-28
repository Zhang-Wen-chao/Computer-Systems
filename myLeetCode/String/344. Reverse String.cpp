// 344. Reverse String
// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};

int main() {
    Solution sol;
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    sol.reverseString(s);
    
    // 输出结果
    for (char ch : s) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    
    return 0;
}