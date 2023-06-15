// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>

class Solution {
  public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        int maxNum = n * n;
        int curNum = 1;
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int row = 0, column = 0;
        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0;
        while (curNum <= maxNum) {
            matrix[row][column] = curNum;
            curNum++;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row = row + directions[directionIndex][0];
            column = column + directions[directionIndex][1];
        }
        return matrix;
    }
};

int main() {
    Solution sol;
    int n = 4;
    std::vector<std::vector<int>> ans = sol.generateMatrix(n);
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            std::cout << ans[row][column] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
