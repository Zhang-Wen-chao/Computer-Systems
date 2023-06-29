// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(std::string str) {
    std::stack<char> stk;
    std::unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : str) {
        if (pairs.count(ch) == 0) {
            stk.push(ch);
        } else {
            if (stk.empty() || stk.top() != pairs[ch]) {
                return false; // 括号不匹配，返回 false
            }
            stk.pop();
        }
    }
    return stk.empty(); // 所有括号都匹配完毕后，栈应该为空
}

int main() {
    // std::string str = "{[]}";
    // std::string str = "()";
    // std::string str = "()[]{}";
    std::string str = "(]";
    // std::string str = "([)]";
    bool result = isValid(str);
    std::cout << "Is parentheses valid? " << std::boolalpha << result << std::endl;
    return 0;
}