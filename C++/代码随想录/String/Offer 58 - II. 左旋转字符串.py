def reverseLeftWords(s, n):
    return s[n:] + s[:n]

# 测试用例
print(reverseLeftWords("abcdefg", 2))  # 应输出: "cdefgab"
print(reverseLeftWords("lrloseumgh", 6))  # 应输出: "umghlrlose"
