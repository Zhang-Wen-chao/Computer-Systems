// LeetCode 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    std::vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2;i < n+1;++i) {
        dp[i] = std::min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }

    return dp[n];
}

int main() {
    std::vector<std::vector<int>> testCases = {{10, 15, 20}, {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}};
    for (auto& testCase: testCases) {
        std::cout << "The minimum cost to reach the top is: " << minCostClimbingStairs(testCase) << std::endl;
    }
    
    return 0;
}

