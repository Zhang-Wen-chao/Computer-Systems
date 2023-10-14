// 150. Evaluate Reverse Polish Notation
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <stack>
#include <vector>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> stk;
    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int op2 = stk.top(); stk.pop();
            int op1 = stk.top(); stk.pop();
            if (token == "+") stk.push(op1 + op2);
            else if (token == "-") stk.push(op1 - op2);
            else if (token == "*") stk.push(op1 * op2);
            else stk.push(op1 / op2);
        } else {
            stk.push(std::stoi(token));
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
