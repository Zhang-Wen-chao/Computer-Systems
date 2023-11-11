def solveSudoku(board):
    def isValid(row, col, c):
        for i in range(9):
            if board[i][col] == c or board[row][i] == c or \
               board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
                return False
        return True

    def solve():
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for c in map(str, range(1, 10)):
                        if isValid(i, j, c):
                            board[i][j] = c
                            if solve():
                                return True
                            board[i][j] = '.'
                    return False
        return True

    solve()

# 测试用例
board = [
    ["5", "3", ".", ".", "7", ".", ".", ".", "."],
    ["6", ".", ".", "1", "9", "5", ".", ".", "."],
    [".", "9", "8", ".", ".", ".", ".", "6", "."],
    ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
    ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
    ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
    [".", "6", ".", ".", ".", ".", "2", "8", "."],
    [".", ".", ".", "4", "1", "9", ".", ".", "5"],
    [".", ".", ".", ".", "8", ".", ".", "7", "9"]
]

solveSudoku(board)

for row in board:
    print(row)
