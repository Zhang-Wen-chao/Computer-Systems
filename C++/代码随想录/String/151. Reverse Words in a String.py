class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split()))

# Test case
sol = Solution()
print(sol.reverseWords("the sky is blue"))  # "blue is sky the"
