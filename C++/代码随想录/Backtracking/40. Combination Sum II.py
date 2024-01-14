def combinationSum2(candidates, target):
    def backtrack(start, path, sum):
        if sum == target:
            result.append(path[:])
            return
        if sum > target:
            return

        for i in range(start, len(candidates)):
            # 跳过重复元素
            if i > start and candidates[i] == candidates[i - 1]:
                continue

            path.append(candidates[i])
            backtrack(i + 1, path, sum + candidates[i])
            path.pop()

    candidates.sort()  # 对候选数组进行排序
    result = []
    backtrack(0, [], 0)
    return result

# 测试用例
candidates = [10, 1, 2, 7, 6, 1, 5]
target = 8
print(combinationSum2(candidates, target))
