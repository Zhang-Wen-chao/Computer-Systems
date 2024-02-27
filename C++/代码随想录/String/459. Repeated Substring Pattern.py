class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s + s)[1:-1]

sol = Solution()

# 测试用例
print(sol.repeatedSubstringPattern("abab"))  # 应输出: True
print(sol.repeatedSubstringPattern("aba"))   # 应输出: False