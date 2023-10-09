// 200. Number of Islands
// https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int numIslands = 0;

        std::vector<std::vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    grid[i][j] = '0'; // mark current cell as visited
                    bfs(grid, i, j, directions);
                }
            }
        }

        return numIslands;
    }

private:
    void bfs(std::vector<std::vector<char>>& grid, int row, int col, std::vector<std::vector<int>>& directions) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        std::queue<std::pair<int, int>> bfsQueue;
        bfsQueue.push({row, col});

        while (!bfsQueue.empty()) {
            int currRow = bfsQueue.front().first;
            int currCol = bfsQueue.front().second;
            bfsQueue.pop();

            for (auto direction : directions) {
                int newRow = currRow + direction[0];
                int newCol = currCol + direction[1];

                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && grid[newRow][newCol] == '1') {
                    grid[newRow][newCol] = '0'; // mark current cell as visited
                    bfsQueue.push({newRow, newCol});
                }
            }
        }
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