// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <iostream>
#include <stack>

std::string removeDuplicates(std::string str) {
    std::stack<char> stk;

    for (char ch : str) {
        if (!stk.empty() && stk.top() == ch) {
            stk.pop(); // 如果栈顶元素与当前字符相同，移除栈顶元素
        } else {
            stk.push(ch); // 否则，将当前字符入栈
        }
    }

    std::string result;
    while (!stk.empty()) {
        result = stk.top() + result; // 逆序构建结果字符串
        stk.pop();
    }

    return result;
}

int main() {
    // std::string str = "abbaca";
    std::string str = "aaabaaaa";
    // std::string str = "abbbabbaca";
    std::string result = removeDuplicates(str);
    std::cout << "String after removal of adjacent duplicates: " << result << std::endl;

    return 0;
}