from typing import List

def minPathSum(grid: List[List[int]]) -> int:
    if not grid or not grid[0]:
        return 0
    
    rows, cols = len(grid), len(grid[0])
    
    # Create a dp table to store the minimum path sum to each cell
    dp = [[0] * cols for _ in range(rows)]
    
    # Initialize the dp table
    dp[0][0] = grid[0][0]
    
    # Fill the first row
    for j in range(1, cols):
        dp[0][j] = dp[0][j - 1] + grid[0][j]
    
    # Fill the first column
    for i in range(1, rows):
        dp[i][0] = dp[i - 1][0] + grid[i][0]
    
    # Fill the rest of the dp table
    for i in range(1, rows):
        for j in range(1, cols):
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
    
    # The bottom-right cell contains the minimum path sum
    return dp[rows - 1][cols - 1]

# 示例 1
grid1 = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
print("示例 1 输出:", minPathSum(grid1))  # 输出应为 7

# 示例 2
grid2 = [[1, 2, 3], [4, 5, 6]]
print("示例 2 输出:", minPathSum(grid2))  # 输出应为 12
