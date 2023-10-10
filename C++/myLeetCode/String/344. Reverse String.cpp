// 344. Reverse String
// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>

void reverseString(std::vector<char>& str) {
    int left = 0;
    int right = str.size() - 1;
    
    while (left < right) {
        std::swap(str[left], str[right]);
        ++left;
        --right;
    }
}

int main() {
    std::vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    reverseString(str);

    for (char ch : str) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    
    return 0;
}