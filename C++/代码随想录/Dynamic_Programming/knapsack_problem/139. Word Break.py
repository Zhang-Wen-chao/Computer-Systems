def wordBreak(s, wordDict):
    word_set = set(wordDict)
    dp = [False] * (len(s) + 1)
    dp[0] = True

    for i in range(1, len(s) + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_set:
                dp[i] = True
                break

    return dp[len(s)]

# 测试用例
print(wordBreak("leetcode", ["leet", "code"]))  # 输出应该是 True
print(wordBreak("applepenapple", ["apple", "pen"]))  # 输出应该是 True
print(wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"]))  # 输出应该是 False
