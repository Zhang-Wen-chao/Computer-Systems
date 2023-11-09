def generateMatrix(n):
    matrix = [[0] * n for _ in range(n)]
    left, right, top, bottom = 0, n - 1, 0, n - 1
    num = 1
    
    while left <= right and top <= bottom:
        # Traverse from left to right.
        for i in range(left, right + 1):
            matrix[top][i] = num
            num += 1
        top += 1
        
        # Traverse downwards.
        for i in range(top, bottom + 1):
            matrix[i][right] = num
            num += 1
        right -= 1
        
        # Traverse from right to left.
        if top <= bottom:
            for i in range(right, left - 1, -1):
                matrix[bottom][i] = num
                num += 1
            bottom -= 1
        
        # Traverse upwards.
        if left <= right:
            for i in range(bottom, top - 1, -1):
                matrix[i][left] = num
                num += 1
            left += 1
    
    return matrix

# Test cases
print(generateMatrix(3))
# Output:
# [
#  [ 1, 2, 3 ],
#  [ 8, 9, 4 ],
#  [ 7, 6, 5 ]
# ]

print(generateMatrix(4))
# Output:
# [
#  [ 1,  2,  3,  4],
#  [12, 13, 14,  5],
#  [11, 16, 15,  6],
#  [10,  9,  8,  7]
# ]
