// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices, int fee) {
    int n = prices.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
    dp[0][0] -= prices[0]; // 持股票
    for (int i = 1; i < n; i++) {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
        dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
    }
    return std::max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {

    std::vector<std::vector<int>> testCases = {
        {1, 3, 2, 8, 4, 9},
        {1, 3, 7, 5, 10, 3}
    };
    std::vector<int> fees = {2, 3};

    for (int i = 0; i < testCases.size(); i++) {
        std::cout << "For the test case " << i + 1 << ", the maximum profit is " << maxProfit(testCases[i], fees[i]) << "." << std::endl;
    }

    return 0;
}