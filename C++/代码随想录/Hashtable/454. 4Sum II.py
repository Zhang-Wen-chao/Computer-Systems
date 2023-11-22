def fourSumCount(A, B, C, D):
    countAB = {}
    for a in A:
        for b in B:
            countAB[a + b] = countAB.get(a + b, 0) + 1

    count = 0
    for c in C:
        for d in D:
            count += countAB.get(-(c + d), 0)

    return count

# 测试用例
print(fourSumCount([1, 2], [-2, -1], [-1, 2], [0, 2]))  # 应该输出 2
