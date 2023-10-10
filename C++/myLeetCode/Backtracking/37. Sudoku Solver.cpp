// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

#include "../printUtils.hpp"

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        backtrack(board);
    }

private:
    bool backtrack(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            if (backtrack(board)) {
                                return true;
                            }
                            board[row][col] = '.';  // 回溯
                        }
                    }
                    return false;  // 所有数字都尝试过都无法满足条件，返回false
                }
            }
        }

        return true;  // 数独已经填满
    }

    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char num) {
        // 检查当前数字在行中是否重复
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num) {
                return false;
            }
        }

        // 检查当前数字在列中是否重复
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num) {
                return false;
            }
        }

        // 检查当前数字在小九宫格中是否重复
        int startRow = 3 * (row / 3);
        int startCol = 3 * (col / 3);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[startRow + i][startCol + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution().solveSudoku(board);
    printArray(board);

    return 0;
}
