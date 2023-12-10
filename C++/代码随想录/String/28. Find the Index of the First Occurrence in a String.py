# 不要用这个，用cpp
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i+len(needle)] == needle:
                return i
        return -1

sol = Solution()

# 测试用例
print(sol.strStr("hello", "ll"))  # 输出: 2
print(sol.strStr("aaaaa", "bba")) # 输出: -1
print(sol.strStr("", ""))         # 输出: 0
