def isAnagram(s, t):
    if len(s) != len(t):
        return False

    countS, countT = {}, {}
    for i in range(len(s)):
        countS[s[i]] = 1 + countS.get(s[i], 0)
        countT[t[i]] = 1 + countT.get(t[i], 0)

    return countS == countT

# 测试用例
print(isAnagram("anagram", "nagaram"))  # 应该输出 True
print(isAnagram("rat", "car"))          # 应该输出 False
