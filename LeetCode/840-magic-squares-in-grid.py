from typing import List

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        def is_magic(square):
            # Flatten the square to check if it contains all numbers 1-9
            flat = [square[i][j] for i in range(3) for j in range(3)]
            if sorted(flat) != list(range(1, 10)):
                return False
            
            # Check if all rows, columns, and diagonals sum to 15
            row_sums = [sum(square[i]) for i in range(3)]
            col_sums = [sum(square[i][j] for i in range(3)) for j in range(3)]
            diag_sum1 = sum(square[i][i] for i in range(3))
            diag_sum2 = sum(square[i][2-i] for i in range(3))
            
            return all(s == 15 for s in row_sums + col_sums + [diag_sum1, diag_sum2])

        count = 0
        rows, cols = len(grid), len(grid[0])

        # Check every 3x3 subgrid in the grid
        for i in range(rows - 2):
            for j in range(cols - 2):
                square = [grid[i+k][j:j+3] for k in range(3)]
                if is_magic(square):
                    count += 1

        return count

# 示例用例
grid = [
    [4, 3, 8, 4],
    [9, 5, 1, 9],
    [2, 7, 6, 2]
]

solution = Solution()
result = solution.numMagicSquaresInside(grid)
print(f"Number of 3x3 magic squares in the grid: {result}")
