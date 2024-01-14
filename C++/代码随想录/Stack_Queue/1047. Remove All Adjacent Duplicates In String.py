class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for char in s:
            if stack and stack[-1] == char:
                stack.pop()
            else:
                stack.append(char)
        return ''.join(stack)

# Test case
sol = Solution()
print(sol.removeDuplicates("abbaca"))  # "ca"
print(sol.removeDuplicates("azxxzy"))  # "ay"
