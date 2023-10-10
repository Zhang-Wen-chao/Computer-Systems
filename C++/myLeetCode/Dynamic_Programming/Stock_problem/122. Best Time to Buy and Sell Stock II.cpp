// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int len = prices.size();
    std::vector<std::vector<int>> dp(len, std::vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // 注意这里是和121. 买卖股票的最佳时机唯一不同的地方。
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[len - 1][1];
}

int main() {
    std::vector<std::vector<int>> testcases = {
        {7, 1, 5, 3, 6, 4},
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