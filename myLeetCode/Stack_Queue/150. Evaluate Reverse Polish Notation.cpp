// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <stack>
#include <vector>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> stk;

    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();

            int result;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else if (token == "/") {
                result = num1 / num2;
            }

            stk.push(result);
        } else {
            int num = std::stoi(token);
            stk.push(num);
        }
    }

    return stk.top();
}

int main() {
    std::vector<std::string> tokens1{"2", "1", "+", "3", "*"};
    std::cout << evalRPN(tokens1) << std::endl; // Output: 9

    std::vector<std::string> tokens2{"4", "13", "5", "/", "+"};
    std::cout << evalRPN(tokens2) << std::endl; // Output: 6

    std::vector<std::string> tokens3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << evalRPN(tokens3) << std::endl; // Output: 22

    return 0;
}
