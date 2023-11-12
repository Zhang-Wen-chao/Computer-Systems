def partitionLabels(S):
    last = {c: i for i, c in enumerate(S)}
    j = anchor = 0
    result = []

    for i, c in enumerate(S):
        j = max(j, last[c])
        if i == j:
            result.append(i - anchor + 1)
            anchor = i + 1

    return result

# 测试用例
print(partitionLabels("ababcbacadefegdehijhklij"))  # 应该输出 [9, 7, 8]
print(partitionLabels("eccbbbbdec"))               # 应该输出 [10]
