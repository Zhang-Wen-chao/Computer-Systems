// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            if (c == ')' && stk.top() != '(') return false;
            if (c == '}' && stk.top() != '{') return false;
            if (c == ']' && stk.top() != '[') return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    // std::string str = "{[]}";
    // std::string str = "()";
    std::string str = "()[]{}";
    // std::string str = "(]";
    // std::string str = "([)]";
    bool result = isValid(str);
    std::cout << "Is parentheses valid? " << std::boolalpha << result << std::endl;
    return 0;
}