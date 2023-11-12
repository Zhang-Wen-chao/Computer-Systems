def strStr(haystack, needle):
    if not needle:
        return 0
    for i in range(len(haystack) - len(needle) + 1):
        if haystack[i:i+len(needle)] == needle:
            return i
    return -1

# 测试用例
print(strStr("hello", "ll"))  # 输出: 2
print(strStr("aaaaa", "bba")) # 输出: -1
print(strStr("", ""))         # 输出: 0
