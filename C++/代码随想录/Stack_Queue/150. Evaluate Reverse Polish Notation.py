from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            if token in "+-*/":
                num2 = stack.pop()
                num1 = stack.pop()
                if token == '+':
                    stack.append(num1 + num2)
                elif token == '-':
                    stack.append(num1 - num2)
                elif token == '*':
                    stack.append(num1 * num2)
                elif token == '/':
                    stack.append(int(num1 / num2))  # 使用整数除法
            else:
                stack.append(int(token))
        return stack.pop()

# Test case
sol = Solution()
print(sol.evalRPN(["2", "1", "+", "3", "*"]))       # 9
print(sol.evalRPN(["4", "13", "5", "/", "+"]))     # 6
print(sol.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))  # 22
