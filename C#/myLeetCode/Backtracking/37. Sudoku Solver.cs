// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/

using System;

public class Solution {
    public void SolveSudoku(char[][] board) {
        Solve(board);
    }

    private bool Solve(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (IsValidMove(board, row, col, num)) {
                            board[row][col] = num;

                            if (Solve(board)) {
                                return true;
                            } else {
                                board[row][col] = '.'; // 回溯
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true; // 数独已解决
    }

    private bool IsValidMove(char[][] board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num || board[i][col] == num || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        char[][] board = new char[][] {
            new char[] { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
            new char[] { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
            new char[] { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
            new char[] { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
            new char[] { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
            new char[] { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
            new char[] { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
            new char[] { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
            new char[] { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
        };

        solution.SolveSudoku(board);

        Console.WriteLine("Solved Sudoku:");
        PrintSudoku(board);
    }

    public static void PrintSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                Console.Write(board[i][j] + " ");
            }
            Console.WriteLine();
        }
    }
}
