def canConstruct(ransomNote, magazine):
    char_count = {}

    for char in magazine:
        char_count[char] = char_count.get(char, 0) + 1

    for char in ransomNote:
        if char_count.get(char, 0) == 0:
            return False
        char_count[char] -= 1

    return True

# 测试用例
print(canConstruct("a", "b"))  # 应该输出 False
print(canConstruct("aa", "ab"))  # 应该输出 False
print(canConstruct("aa", "aab"))  # 应该输出 True
