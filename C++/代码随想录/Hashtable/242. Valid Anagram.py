class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        countS, countT = {}, {}
        for i in range(len(s)):
            countS[s[i]] = 1 + countS.get(s[i], 0)
            countT[t[i]] = 1 + countT.get(t[i], 0)

        return countS == countT

sol = Solution()

# 测试用例
print(sol.isAnagram("anagram", "nagaram"))  # 应该输出 True
print(sol.isAnagram("rat", "car"))          # 应该输出 False
