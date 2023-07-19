// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // 如果起点或终点有障碍物，则路径数为 0
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }

    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));

    // 初始化边界条件
    dp[0][0] = 1;
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = dp[i-1][0];
        }
    }
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = dp[0][j-1];
        }
    }

    // 动态规划计算路径数
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

int main() {
    std::vector<std::vector<std::vector<int>>> testCases = {
        {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}},
        {{0, 1}, {0, 0}}
    };
    for (auto& testCase: testCases) {
        std::cout << "Number of unique paths: " << uniquePathsWithObstacles(testCase) << std::endl;
    }
    
    return 0;
}

