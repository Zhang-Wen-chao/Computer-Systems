// 剑指 Offer 05. 替换空格
// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/

#include <iostream>
#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s) {
        std::string result;
        
        for (char ch : s) {
            if (ch == ' ') {
                result += "%20";
            } else {
                result += ch;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::string s = "We are happy.";
    
    std::string result = sol.replaceSpace(s);
    
    std::cout << result << std::endl;
    
    return 0;
}
