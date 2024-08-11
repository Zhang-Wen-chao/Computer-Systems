from typing import List

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        # Prefix sums for rows and columns
        row_sum = [[0] * (cols + 1) for _ in range(rows)]
        col_sum = [[0] * (rows + 1) for _ in range(cols)]

        # Calculate the prefix sums
        for i in range(rows):
            for j in range(cols):
                row_sum[i][j + 1] = row_sum[i][j] + grid[i][j]
                col_sum[j][i + 1] = col_sum[j][i] + grid[i][j]

        def get_row_sum(r, c1, c2):
            return row_sum[r][c2 + 1] - row_sum[r][c1]

        def get_col_sum(c, r1, r2):
            return col_sum[c][r2 + 1] - col_sum[c][r1]

        def get_diag_sum(r, c, size):
            return sum(grid[r + i][c + i] for i in range(size))

        def get_anti_diag_sum(r, c, size):
            return sum(grid[r + i][c + size - 1 - i] for i in range(size))

        # Check for the largest magic square
        for size in range(min(rows, cols), 1, -1):
            for r in range(rows - size + 1):
                for c in range(cols - size + 1):
                    target_sum = get_row_sum(r, c, c + size - 1)
                    if all(get_row_sum(r + i, c, c + size - 1) == target_sum for i in range(size)) and \
                       all(get_col_sum(c + i, r, r + size - 1) == target_sum for i in range(size)) and \
                       get_diag_sum(r, c, size) == target_sum and \
                       get_anti_diag_sum(r, c, size) == target_sum:
                        return size
        return 1

# 示例用例
grid = [
    [7, 1, 4, 5, 6],
    [2, 5, 1, 6, 4],
    [1, 5, 4, 3, 2],
    [1, 2, 7, 3, 4]
]

solution = Solution()
result = solution.largestMagicSquare(grid)
print(f"The size of the largest magic square is: {result}")
