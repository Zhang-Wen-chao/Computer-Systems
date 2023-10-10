// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

using System;

public class Solution {
    public int[][] GenerateMatrix(int n) {
        int[][] matrix = new int[n][];
        for (int i = 0; i < n; i++) {
            matrix[i] = new int[n];
        }
        
        int left = 0, top = 0;
        int right = n - 1, bottom = n - 1;
        int num = 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = num++;
            }
            for (int i = top + 1; i <= bottom; i++) {
                matrix[i][right] = num++;
            }
            if (left < right && top < bottom) {
                for (int i = right - 1; i > left; i--) {
                    matrix[bottom][i] = num++;
                }
                for (int i = bottom; i > top; i--) {
                    matrix[i][left] = num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();
        int n = 3; // You can change this to test other sizes.
        int[][] result = solution.GenerateMatrix(n);

        // Print the matrix to the console
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Console.Write(result[i][j] + "\t");
            }
            Console.WriteLine();
        }
    }
}
