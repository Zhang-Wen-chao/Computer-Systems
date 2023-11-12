def largestSumAfterKNegations(A, K):
    A.sort()
    for i in range(len(A)):
        if A[i] < 0 and K > 0:
            A[i] = -A[i]
            K -= 1
    if K % 2 == 1:
        A.sort()
        A[0] = -A[0]
    return sum(A)

# 测试用例
print(largestSumAfterKNegations([4, 2, 3], 1))  # 应该输出 5
print(largestSumAfterKNegations([3, -1, 0, 2], 3))  # 应该输出 6
print(largestSumAfterKNegations([2, -3, -1, 5, -4], 2))  # 应该输出 13
