// 738. Monotone Increasing Digits
// https://leetcode.com/problems/monotone-increasing-digits/

#include <iostream>
#include <string>

int monotoneIncreasingDigits(int n) {
    std::string s = std::to_string(n);

    int i = s.size() - 1;
    while (i > 0 && s[i] < s[i-1]) {
        s[i-1]--;
        i--;
    }

    for (int j = i+1; j < s.size(); j++) {
        s[j] = '9';
    }

    return std::stoi(s);
}

int main() {
    std::cout << "The largest number with monotone increasing digits is: " << monotoneIncreasingDigits(10) << std::endl;

    std::cout << "The largest number with monotone increasing digits is: " << monotoneIncreasingDigits(1234) << std::endl;

    std::cout << "The largest number with monotone increasing digits is: " << monotoneIncreasingDigits(332) << std::endl;

    return 0;
}