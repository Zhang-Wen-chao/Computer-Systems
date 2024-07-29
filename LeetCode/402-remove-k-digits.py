def removeKdigits(num, k):
    stack = []

    for digit in num:
        # 移除比栈顶元素更大的数字，以便生成更小的数字
        while k > 0 and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)

    # 如果仍然有剩余的k，从尾部移除数字
    while k > 0:
        stack.pop()
        k -= 1

    # 移除前导零
    while stack and stack[0] == '0':
        stack.pop(0)

    # 构建最小可能的数字
    return ''.join(stack) if stack else '0'

num = "1432219"
k = 3
result = removeKdigits(num, k)
print(result)  # 输出结果为 "1219"