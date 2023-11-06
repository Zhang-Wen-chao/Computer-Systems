// 344. Reverse String
// https://leetcode.com/problems/reverse-string/
#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
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