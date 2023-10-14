// 51. N-Queens
// https://leetcode.com/problems/n-queens/

using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<string>> SolveNQueens(int n) {
        IList<IList<string>> result = new List<IList<string>>();
        char[][] board = new char[n][];
        for (int i = 0; i < n; i++) {
            board[i] = new char[n];
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        SolveNQueensHelper(board, 0, result);
        return result;
    }

    private void SolveNQueensHelper(char[][] board, int row, IList<IList<string>> result) {
        if (row == board.Length) {
            result.Add(BoardToStringList(board));
            return;
        }

        for (int col = 0; col < board.Length; col++) {
            if (IsSafe(board, row, col)) {
                board[row][col] = 'Q';
                SolveNQueensHelper(board, row + 1, result);
                board[row][col] = '.';
            }
        }
    }

    private bool IsSafe(char[][] board, int row, int col) {
        // Check if there's a queen in the same column above the current row
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check if there's a queen in the upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check if there's a queen in the upper right diagonal
        for (int i = row, j = col; i >= 0 && j < board.Length; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    private IList<string> BoardToStringList(char[][] board) {
        IList<string> result = new List<string>();
        foreach (var row in board) {
            result.Add(new string(row));
        }
        return result;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int n = 4;
        IList<IList<string>> result = solution.SolveNQueens(n);

        Console.WriteLine($"All solutions for {n}-Queens problem:");
        foreach (var solutionBoard in result) {
            foreach (var row in solutionBoard) {
                Console.WriteLine(row);
            }
            Console.WriteLine();
        }
    }
}
