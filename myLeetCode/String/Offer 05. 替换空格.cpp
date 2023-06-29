// 剑指 Offer 05. 替换空格
// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/

#include <iostream>
#include <string>

std::string replaceSpace(std::string str) {
    std::string result;
    
    for (char ch : str) {
        if (ch == ' ') {
            result += "%20";
        } else {
            result += ch;
        }
    }
    
    return result;
}

int main() {
    std::string str = "We are happy.";
    
    std::string result = replaceSpace(str);
    
    std::cout << result << std::endl;
    
    return 0;
}
