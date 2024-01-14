def combine(n, k):
    def backtrack(start, path):
        if len(path) == k:
            result.append(path[:])
            return
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1, path)
            path.pop()

    result = []
    backtrack(1, [])
    return result

# 测试用例
n = 4
k = 2
print(combine(n, k))
