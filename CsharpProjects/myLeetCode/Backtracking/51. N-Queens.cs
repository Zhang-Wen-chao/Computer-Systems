// 51. N-Queens
// https://leetcode.com/problems/n-queens/

#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.')); // 初始化棋盘

        backtrack(board, 0, solutions);
        return solutions;
    }

private:
    void backtrack(std::vector<std::string>& board, int row, std::vector<std::vector<std::string>>& solutions) {
        if (row == board.size()) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); ++col) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(board, row + 1, solutions);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(const std::vector<std::string>& board, int row, int col) {
        // 检查当前位置的列是否有其他皇后
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // 检查当前位置的左上方是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // 检查当前位置的右上方是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    printSet(Solution().solveNQueens(4));
    
    return 0;
}