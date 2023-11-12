def evalRPN(tokens):
    stack = []

    for token in tokens:
        if token in "+-*/":
            b = stack.pop()
            a = stack.pop()
            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(int(a / b))  # 使用整数除法
        else:
            stack.append(int(token))

    return stack.pop()

# 测试用例
print(evalRPN(["2", "1", "+", "3", "*"]))  # 输出 9
print(evalRPN(["4", "13", "5", "/", "+"]))  # 输出 6
print(evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))  # 输出 22
