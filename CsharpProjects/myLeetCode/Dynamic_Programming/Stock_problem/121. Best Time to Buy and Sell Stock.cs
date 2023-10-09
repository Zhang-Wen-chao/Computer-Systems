// 121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int len = prices.size();
    if (len == 0) return 0;
    std::vector<std::vector<int>> dp(len, std::vector<int>(2));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
}

int main() {
    std::vector<std::vector<int>> testcases = {
        {7, 1, 5, 3, 6, 4},
        {7, 6, 4, 3, 1},
        {1, 2, 3, 4, 5},
        {2, 4, 1},
        {3}
    };

    for (int i = 0; i < testcases.size(); i++) {
        std::cout << "Max Profit: " << maxProfit(testcases[i]) << std::endl;
    }

    return 0;
}