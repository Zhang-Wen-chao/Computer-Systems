def findSubsequences(nums):
    res = set()

    def dfs(start, path):
        if len(path) > 1:
            res.add(tuple(path))
        for i in range(start, len(nums)):
            if not path or nums[i] >= path[-1]:
                dfs(i + 1, path + [nums[i]])

    dfs(0, [])
    return list(res)

# 测试用例
nums = [4, 6, 7, 7]
print(findSubsequences(nums))
