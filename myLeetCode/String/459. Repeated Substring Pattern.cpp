// 459. Repeated Substring Pattern
// https://leetcode.com/problems/repeated-substring-pattern/

#include <iostream>

bool repeatedSubstringPattern(std::string s) {
    int len = s.length();
    
    for (int i = 1; i <= len / 2; i++) {
        if (len % i == 0) {
            std::string substring = s.substr(0, i);
            std::string repeated = "";
            
            for (int j = 0; j < len / i; j++) {
                repeated += substring;
            }
            
            if (repeated == s) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    std::string s = "abab";
    
    bool result = repeatedSubstringPattern(s);
    
    std::cout << "Is repeated substring pattern: " << std::boolalpha << result << std::endl;
    
    return 0;
}