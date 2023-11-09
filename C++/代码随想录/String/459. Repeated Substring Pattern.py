def repeatedSubstringPattern(s):
    return s in (s + s)[1:-1]

# 测试用例
print(repeatedSubstringPattern("abab"))  # 应输出: True
print(repeatedSubstringPattern("aba"))   # 应输出: False
print(repeatedSubstringPattern("abcabcabcabc"))  # 应输出: True
