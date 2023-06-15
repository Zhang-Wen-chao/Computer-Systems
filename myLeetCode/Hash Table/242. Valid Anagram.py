# 242. Valid Anagram
# https://leetcode.com/problems/valid-anagram/

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        table = [0] * 26
        for ch in s:
            table[ord(ch) - ord('a')] += 1
        for ch in t:
            table[ord(ch) - ord('a')] -= 1
            if table[ord(ch) - ord('a')] < 0:
                return False
        return True

def main():
    solution = Solution()
    print(solution.isAnagram("anagram", "nagaram"))

if __name__ == "__main__":
    main()