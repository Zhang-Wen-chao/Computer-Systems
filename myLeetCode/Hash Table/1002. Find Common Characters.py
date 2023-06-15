# 1002. Find Common Characters
# https://leetcode.com/problems/find-common-characters/

class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        minfreq = [float('inf')] * 26
        for word in words:
            freq = [0] * 26
            for ch in word:
                freq[ord(ch) - ord('a')] += 1
            for i in range(26):
                minfreq[i] = min(minfreq[i], freq[i])
        ans = []
        for i in range(26):
            ans.extend([chr(i + ord('a'))] * minfreq[i])
        return ans
    
def main():
    sol = Solution()
    words = ["bella","label","roller"]
    ans = sol.commonChars(words)
    print(ans)

if __name__ == "__main__":
    main()