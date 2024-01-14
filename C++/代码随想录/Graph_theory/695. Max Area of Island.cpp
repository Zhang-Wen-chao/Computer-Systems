// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

#include <iostream>
#include <vector>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == 1) {
                    int currentArea = 0;
                    dfs(grid, i, j, currentArea);
                    maxArea = std::max(maxArea, currentArea);
                }
            }
        }

        return maxArea;
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int row, int col, int& currentArea) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        // Check if current cell is out of bounds or not part of the island
        if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1) {
            return;
        }

        // Mark current cell as visited by changing its value to 0
        grid[row][col] = 0;
        currentArea++;

        // Recursive call to explore neighboring cells
        dfs(grid, row - 1, col, currentArea); // up
        dfs(grid, row + 1, col, currentArea); // down
        dfs(grid, row, col - 1, currentArea); // left
        dfs(grid, row, col + 1, currentArea); // right
    }
};

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

    Solution solution;
    int maxArea = solution.maxAreaOfIsland(grid);

    std::cout << "Max area of island: " << maxArea << std::endl;

	return 0;
}