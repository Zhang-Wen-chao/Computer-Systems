from collections import Counter

def commonChars(A):
    min_freq = Counter(A[0])
    for a in A[1:]:
        min_freq &= Counter(a)
    return list(min_freq.elements())

# 测试用例
print(commonChars(["bella", "label", "roller"]))  # 应该输出 ['e', 'l', 'l']
