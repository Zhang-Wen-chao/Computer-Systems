def is_magic_square(matrix):
    n = len(matrix)

    # Calculate the sum of the first row as the target sum
    target_sum = sum(matrix[0])

    # Check the sum of all rows
    for row in matrix:
        if sum(row) != target_sum:
            return False

    # Check the sum of all columns
    for col in range(n):
        col_sum = sum(matrix[row][col] for row in range(n))
        if col_sum != target_sum:
            return False

    # Check the sum of the main diagonal
    if sum(matrix[i][i] for i in range(n)) != target_sum:
        return False

    # Check the sum of the anti-diagonal
    if sum(matrix[i][n-1-i] for i in range(n)) != target_sum:
        return False

    return True

# 示例输入
matrix = [
    [4, 9, 2],
    [3, 5, 7],
    [8, 1, 6]
]

# 检查是否为幻方
print(is_magic_square(matrix))  # 输出: True
