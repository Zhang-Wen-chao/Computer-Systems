// 541. Reverse String II
// https://leetcode.com/problems/reverse-string-ii/

#include <iostream>

std::string reverseStr(std::string str, int k) {
    int n = str.length();
    
    for (int i = 0; i < n; i += 2 * k) {
        int left = i;
        int right = std::min(i + k - 1, n - 1);
        
        while (left < right) {
            std::swap(str[left], str[right]);
            ++left;
            --right;
        }
    }
    
    return str;
}

int main() {
    std::string str = "abcdefg";
    int k = 2;
    
    std::string result = reverseStr(str, k);
    
    std::cout << result << std::endl;
    
    return 0;
}