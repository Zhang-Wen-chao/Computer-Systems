def combinationSum3(k, n):
    def backtrack(start, remaining, path):
        if len(path) == k and remaining == 0:
            result.append(path[:])
            return
        for i in range(start, 10):
            if remaining - i < 0:
                break
            backtrack(i + 1, remaining - i, path + [i])

    result = []
    backtrack(1, n, [])
    return result

# 测试用例
k = 3
n = 9
print(combinationSum3(k, n))
