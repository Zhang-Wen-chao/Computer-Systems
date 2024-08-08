from typing import List
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m, n = len(matrix), len(matrix[0])
        row, col = [False] * m, [False] * n

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    row[i] = col[j] = True
        
        for i in range(m):
            for j in range(n):
                if row[i] or col[j]:
                    matrix[i][j] = 0

# 示例
matrix = [
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1]
]

Solution().setZeroes(matrix)
print(matrix)
# 输出：[[1, 0, 1], [0, 0, 0], [1, 0, 1]]