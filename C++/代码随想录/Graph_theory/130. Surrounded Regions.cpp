// 130. Surrounded Regions
// https://leetcode.com/problems/surrounded-regions/

#include <iostream>
#include <vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int numRows = board.size();
        int numCols = board[0].size();

        // Check all border cells and mark 'O' connected cells as temporary mark '#'
        for (int i = 0; i < numRows; ++i) {
            dfs(board, i, 0);
            dfs(board, i, numCols - 1);
        }
        for (int j = 0; j < numCols; ++j) {
            dfs(board, 0, j);
            dfs(board, numRows - 1, j);
        }

        // Replace 'O' with 'X' and '#' with 'O'
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(std::vector<std::vector<char>>& board, int row, int col) {
        int numRows = board.size();
        int numCols = board[0].size();

        // Check if current cell is out of bounds or not 'O'
        if (row < 0 || row >= numRows || col < 0 || col >= numCols || board[row][col] != 'O') {
            return;
        }

        // Mark current cell as temporary mark '#'
        board[row][col] = '#';

        // Recursive call to explore neighboring cells
        dfs(board, row - 1, col); // up
        dfs(board, row + 1, col); // down
        dfs(board, row, col - 1); // left
        dfs(board, row, col + 1); // right
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    Solution solution;
    solution.solve(board);

    std::cout << "Updated board:" << std::endl;
    for (const auto& row : board) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}