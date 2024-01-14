def maxAreaOfIsland(grid):
    if not grid:
        return 0

    def dfs(r, c):
        if 0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] == 1:
            grid[r][c] = 0  # Mark as visited
            return 1 + dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1)
        return 0

    max_area = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                max_area = max(max_area, dfs(i, j))

    return max_area

# 测试用例
grid = [
    [0, 1, 0, 0, 0],
    [1, 1, 0, 0, 0],
    [0, 0, 0, 1, 1],
    [0, 0, 0, 1, 1]
]
print(maxAreaOfIsland(grid))
