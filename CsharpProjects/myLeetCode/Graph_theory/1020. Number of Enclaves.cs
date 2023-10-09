// 1020. Number of Enclaves
// https://leetcode.com/problems/number-of-enclaves/description/

#include <iostream>
#include <vector>

class Solution {
public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        // Mark border land as visited (0)
        for (int i = 0; i < numRows; ++i) {
            dfs(grid, i, 0);
            dfs(grid, i, numCols - 1);
        }
        for (int j = 0; j < numCols; ++j) {
            dfs(grid, 0, j);
            dfs(grid, numRows - 1, j);
        }

        // Count remaining land
        int numEnclaves = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == 1) {
                    numEnclaves++;
                }
            }
        }

        return numEnclaves;
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int row, int col) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        // Check if current cell is out of bounds or not part of the land
        if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] != 1) {
            return;
        }

        // Mark current cell as visited by changing its value to 0
        grid[row][col] = 0;

        // Recursive call to explore neighboring cells
        dfs(grid, row - 1, col); // up
        dfs(grid, row + 1, col); // down
        dfs(grid, row, col - 1); // left
        dfs(grid, row, col + 1); // right
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<std::vector<int>>> testCases = {
        {
            {0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 0}
        }
    };

    for (int i = 0; i < testCases.size(); ++i) {
        int numEnclaves = solution.numEnclaves(testCases[i]);
        std::cout << "Number of enclaves: " << numEnclaves << std::endl;
    }

    return 0;
}