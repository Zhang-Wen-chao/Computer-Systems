from typing import List
from collections import Counter

class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        char_count = Counter(words[0])
        for word in words[1:]:
            char_count &= Counter(word)
        return list(char_count.elements())

sol = Solution()

# 测试用例
print(sol.commonChars(["bella", "label", "roller"]))  # 应该输出 ['e', 'l', 'l']
