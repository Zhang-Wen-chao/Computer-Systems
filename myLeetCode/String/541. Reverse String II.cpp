// 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/

#include <iostream>

class Solution {
public:
    std::string reverseStr(std::string s, int k) {
        int n = s.length();
        
        for (int i = 0; i < n; i += 2 * k) {
            int left = i;
            int right = std::min(i + k - 1, n - 1);
            
            while (left < right) {
                std::swap(s[left], s[right]);
                ++left;
                --right;
            }
        }
        
        return s;
    }
};

int main() {
    Solution sol;
    std::string s = "abcdefg";
    int k = 2;
    
    std::string result = sol.reverseStr(s, k);
    
    std::cout << result << std::endl;
    
    return 0;
}