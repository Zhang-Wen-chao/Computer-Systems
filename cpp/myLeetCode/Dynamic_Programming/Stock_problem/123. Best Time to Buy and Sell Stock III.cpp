// 123. Best Time to Buy and Sell Stock III
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// 一天一共就有五个状态，

// 0. 没有操作  （其实我们也可以不设置这个状态）
// 1. 第一次持有股票
// 2. 第一次不持有股票 
// 3. 第二次持有股票
// 4. 第二次不持有股票

#include <iostream>
#include <vector>
#include <climits>

int maxProfit(std::vector<int>& prices) {
    if (prices.size() == 0) return 0;
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = std::max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = std::max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = std::max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[prices.size() - 1][4];
}

int main() {
    std::vector<std::vector<int>> testcases = {
        {3, 3, 5, 0, 0, 3, 1, 4},
        {1, 2, 3, 4, 5},
        {7, 6, 4, 3, 1},
        {2, 4, 1},
        {3}
    };

    for (int i = 0; i < testcases.size(); i++) {
        int result = maxProfit(testcases[i]);
        std::cout << "Max Profit: " << result << std::endl;
    }

    return 0;
}