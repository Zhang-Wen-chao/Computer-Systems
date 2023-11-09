def isValid(s: str):
    # 使用字典来存储括号的对应关系
    bracket_map = {")": "(", "}": "{", "]": "["}
    stack = []

    for char in s:
        if char in bracket_map:
            top_element = stack.pop() if stack else '#'
            if bracket_map[char] != top_element:
                return False
        else:
            stack.append(char)

    return not stack

# 测试用例
print(isValid("()"))        # 应该返回 True
print(isValid("()[]{}"))    # 应该返回 True
print(isValid("(]"))        # 应该返回 False
print(isValid("([)]"))      # 应该返回 False
print(isValid("{[]}"))      # 应该返回 True
