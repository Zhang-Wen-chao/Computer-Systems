// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int numIslands = 0;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }

        return numIslands;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid, int row, int col) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        if (row < 0 || col < 0 || row >= numRows || col >= numCols || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0'; // mark current cell as visited

        dfs(grid, row - 1, col); // up
        dfs(grid, row + 1, col); // down
        dfs(grid, row, col - 1); // left
        dfs(grid, row, col + 1); // right
    }
};

int main() {
    std::vector<std::vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };

    std::vector<std::vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution solution;

    std::cout << "Number of islands in grid1: " << solution.numIslands(grid1) << std::endl;
    std::cout << "Number of islands in grid2: " << solution.numIslands(grid2) << std::endl;

    return 0;
}