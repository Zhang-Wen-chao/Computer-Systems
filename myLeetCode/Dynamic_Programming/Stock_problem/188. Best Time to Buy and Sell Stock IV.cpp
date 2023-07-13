// 188. Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// * 0 表示不操作
// * 1 第一次买入
// * 2 第一次卖出
// * 3 第二次买入
// * 4 第二次卖出
// * .....

// **大家应该发现规律了吧 ，除了0以外，偶数就是卖出，奇数就是买入**。

#include <iostream>
#include <vector>
#include <climits>

int maxProfit(int k, std::vector<int>& prices) {
    if (prices.size() == 0) return 0;
    std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2 * k + 1, 0));
    for (int j = 1; j < 2 * k; j += 2) {
        dp[0][j] = -prices[0];
    }
    for (int i = 1; i < prices.size(); i++) {
        for (int j = 0; j < 2 * k - 1; j += 2) {
            dp[i][j + 1] = std::max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
            dp[i][j + 2] = std::max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
        }
    }
    return dp[prices.size() - 1][2 * k];
}

int main() {
    // Test cases
    std::vector<std::vector<int>> testCases = {
        {3, 3, 5, 0, 0, 3, 1, 4},
        {1, 2, 3, 4, 5},
        {7, 6, 4, 3, 1},
        {2, 4, 1},
        {3, 2, 6, 5, 0, 3}
    };

    std::vector<int> target = {2, 3, 0, 2, 2};

    for (int i = 0; i < testCases.size(); i++) {
        int result = maxProfit(target[i], testCases[i]);

        std::cout << "For the array: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the maximum profit with at most " << target[i] << " transactions is " << result << "." << std::endl;
    }

    return 0;
}