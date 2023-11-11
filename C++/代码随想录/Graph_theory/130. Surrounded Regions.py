def solve(board):
    if not board:
        return

    rows, cols = len(board), len(board[0])

    def dfs(r, c):
        if 0 <= r < rows and 0 <= c < cols and board[r][c] == 'O':
            board[r][c] = 'D'
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

    # Mark 'O's on the border and connected to border as 'D'
    for i in range(rows):
        dfs(i, 0)
        dfs(i, cols - 1)

    for j in range(cols):
        dfs(0, j)
        dfs(rows - 1, j)

    # Flip 'O' to 'X', 'D' back to 'O'
    for i in range(rows):
        for j in range(cols):
            if board[i][j] == 'O':
                board[i][j] = 'X'
            elif board[i][j] == 'D':
                board[i][j] = 'O'

# 测试用例
board = [["X","X","X","X"],
         ["X","O","O","X"],
         ["X","X","O","X"],
         ["X","O","X","X"]]
solve(board)
for row in board:
    print(row)
