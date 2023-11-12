def numEnclaves(grid):
    def dfs(i, j):
        if 0 <= i < len(grid) and 0 <= j < len(grid[0]) and grid[i][j] == 1:
            grid[i][j] = 0
            for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                dfs(x, y)

    # 标记边界上和边界相连的陆地
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if i in [0, len(grid)-1] or j in [0, len(grid[0])-1]:
                dfs(i, j)

    # 计算剩余的陆地单元格
    return sum(sum(row) for row in grid)

# 测试用例
grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
print(numEnclaves(grid))
