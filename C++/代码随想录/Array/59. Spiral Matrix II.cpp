// 59. Spiral Matrix II
// https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int num = 1;
        int row = 0, col = 0;
        std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;

        while (num <= n * n) {
            if (row >= 0 && row < n && col >= 0 && col < n && matrix[row][col] == 0) {
                matrix[row][col] = num++;
                row += directions[dir][0];
                col += directions[dir][1];
            } else {
                // 回退一步并改变方向
                row -= directions[dir][0];
                col -= directions[dir][1];
                dir = (dir + 1) % 4;
                row += directions[dir][0];
                col += directions[dir][1];
            }
        }
        return matrix;
    }
};

int main() {
    Solution sol;
    int n = 4;
    std::vector<std::vector<int>> result = sol.generateMatrix(n);

    // 打印结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
