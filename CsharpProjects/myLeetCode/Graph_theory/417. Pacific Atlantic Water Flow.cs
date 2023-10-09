// 417. Pacific Atlantic Water Flow
// https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> result;

        if (matrix.empty()) {
            return result;
        }

        int numRows = matrix.size();
        int numCols = matrix[0].size();
        std::vector<std::vector<bool>> canReachPacific(numRows, std::vector<bool>(numCols, false));
        std::vector<std::vector<bool>> canReachAtlantic(numRows, std::vector<bool>(numCols, false));
        std::queue<std::pair<int, int>> pacificQueue;
        std::queue<std::pair<int, int>> atlanticQueue;

        // Add all cells in first row and column to Pacific queue
        for (int i = 0; i < numRows; ++i) {
            pacificQueue.push({i, 0});
        }
        for (int j = 0; j < numCols; ++j) {
            pacificQueue.push({0, j});
        }
        // Add all cells in last row and column to Atlantic queue
        for (int i = 0; i < numRows; ++i) {
            atlanticQueue.push({i, numCols - 1});
        }
        for (int j = 0; j < numCols; ++j) {
            atlanticQueue.push({numRows - 1, j});
        }

        bfs(matrix, pacificQueue, canReachPacific);
        bfs(matrix, atlanticQueue, canReachAtlantic);

        // Find cells that can reach both Pacific and Atlantic
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void bfs(const std::vector<std::vector<int>>& matrix, std::queue<std::pair<int, int>>& q, std::vector<std::vector<bool>>& visited) {
        static const std::vector<std::pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            visited[row][col] = true;

            for (const auto& dir : dirs) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;

                if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols
                    && matrix[newRow][newCol] >= matrix[row][col] && !visited[newRow][newCol]) {
                    q.push({newRow, newCol});
                }
            }
        }
    }
};

int main() {
    std::vector<std::vector<std::vector<int>>> testCases = {
        {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
        },
        {
            {2, 1},
            {1, 2}
        }
    };

    Solution solution;

    for (int i = 0; i < testCases.size(); i++) {
        std::vector<std::vector<int>> result = solution.pacificAtlantic(testCases[i]);

        std::cout << "Cells that can reach both Pacific and Atlantic:" << std::endl;
        for (const auto& cell : result) {
            std::cout << "(" << cell[0] << ", " << cell[1] << ") ";
        }
    std::cout << std::endl;
    }

    return 0;
}