// 63. Unique Paths II
// https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
	    if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1) //如果在起点或终点出现了障碍，直接返回0
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution sol;
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << sol.uniquePathsWithObstacles(grid) << endl;
    return 0;
}


// 这个解决方案使用了动态规划的思想，用一个二维数组dp来存储子问题的解。dp[i][j]表示从左上角到达grid[i][j]的不同路径数。状态转移方程是：

// - 如果grid[0][0]==1或者grid[m-1[n-1]==1，那么返回零
// - 如果i==j==零，那么dp[零零]=一
// - 如果i>零并且grid[i零]==零，那么dp[i零]=dp[i-一零]
// - 如果i>零并且grid[i零]==一，那么dp[i零]=零
// - 如果j>零并且grid[零[j]==零，那么dp[零[j]=dp[零[j-一]
// - 如果j>零并且grid[零[j]==一，那么dp[零[j]=零
// - 如果i>一并且j>一，并且grid[[i[j]== 零，那么dp[[i[j]=dp[[i-一[j]+dp[[i[j-一]
// - 如果i>一并且j>一，并且grid[[i[j]== 雷，那么dp[[i[j]= 雷

// 最后返回dp[m - one[n - one。