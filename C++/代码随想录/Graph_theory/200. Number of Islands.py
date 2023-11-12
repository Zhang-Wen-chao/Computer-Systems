def numIslands(grid):
    if not grid:
        return 0

    rows, cols = len(grid), len(grid[0])
    num_islands = 0

    def dfs(r, c):
        if 0 <= r < rows and 0 <= c < cols and grid[r][c] == '1':
            grid[r][c] = '0'  # Mark as visited
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == '1':
                dfs(r, c)
                num_islands += 1

    return num_islands

# 测试用例
grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
]
print(numIslands(grid))  # 输出: 1
