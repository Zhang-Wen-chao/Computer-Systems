// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/

#include <iostream>

bool repeatedSubstringPattern(std::string str) {
    int len = str.length();
    
    for (int i = 1; i <= len / 2; i++) {
        if (len % i == 0) {
            std::string substring = str.substr(0, i);
            std::string repeated = "";
            
            for (int j = 0; j < len / i; j++) {
                repeated += substring;
            }
            
            if (repeated == str) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    std::string str = "abab";
    
    bool result = repeatedSubstringPattern(str);
    
    std::cout << "Is repeated substring pattern: " << std::boolalpha << result << std::endl;
    
    return 0;
}