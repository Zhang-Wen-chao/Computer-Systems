def combinationSum(candidates, target):
    def backtrack(start, path, sum):
        if sum == target:
            result.append(path[:])
            return
        if sum > target:
            return

        for i in range(start, len(candidates)):
            path.append(candidates[i])
            backtrack(i, path, sum + candidates[i])
            path.pop()

    result = []
    backtrack(0, [], 0)
    return result

# 测试用例
candidates = [2, 3, 6, 7]
target = 7
print(combinationSum(candidates, target))
