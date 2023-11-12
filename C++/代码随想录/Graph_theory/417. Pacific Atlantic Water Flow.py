def pacificAtlantic(matrix):
    if not matrix or not matrix[0]:
        return []

    def dfs(r, c, visited, prevHeight):
        if (r, c) in visited or r < 0 or c < 0 or r >= len(matrix) or c >= len(matrix[0]) or matrix[r][c] < prevHeight:
            return
        visited.add((r, c))
        for dr, dc in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            dfs(r + dr, c + dc, visited, matrix[r][c])

    rows, cols = len(matrix), len(matrix[0])
    pacific, atlantic = set(), set()

    for i in range(rows):
        dfs(i, 0, pacific, matrix[i][0])
        dfs(i, cols - 1, atlantic, matrix[i][cols - 1])

    for j in range(cols):
        dfs(0, j, pacific, matrix[0][j])
        dfs(rows - 1, j, atlantic, matrix[rows - 1][j])

    return list(pacific & atlantic)

# 测试用例
matrix = [
    [1, 2, 2, 3, 5],
    [3, 2, 3, 4, 4],
    [2, 4, 5, 3, 1],
    [6, 7, 1, 4, 5],
    [5, 1, 1, 2, 4]
]
print(pacificAtlantic(matrix))
