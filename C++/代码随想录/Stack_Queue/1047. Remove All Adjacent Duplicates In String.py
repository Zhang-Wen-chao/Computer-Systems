def removeDuplicates(S):
    stack = []
    for char in S:
        if stack and stack[-1] == char:
            stack.pop()
        else:
            stack.append(char)
    return ''.join(stack)

# 测试用例
print(removeDuplicates("abbaca"))  # 输出: "ca"
print(removeDuplicates("azxxzy"))  # 输出: "ay"
