def isValid(s):
    stack = []
    mapping = {")": "(", "}": "{", "]": "["}

    for char in s:
        if char in mapping:
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.append(char)

    return not stack

# 测试用例
print(isValid("()"))  # 应输出 True
print(isValid("()[]{}"))  # 应输出 True
print(isValid("(]"))  # 应输出 False
print(isValid("([)]"))  # 应输出 False
print(isValid("{[]}"))  # 应输出 True
