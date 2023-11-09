def reverseStr(s, k):
    s = list(s)
    for i in range(0, len(s), 2*k):
        s[i:i+k] = reversed(s[i:i+k])
    return ''.join(s)

# 测试用例
print(reverseStr("abcdefg", 2))  # 应输出: "bacdfeg"
print(reverseStr("abcd", 2))     # 应输出: "bacd"
