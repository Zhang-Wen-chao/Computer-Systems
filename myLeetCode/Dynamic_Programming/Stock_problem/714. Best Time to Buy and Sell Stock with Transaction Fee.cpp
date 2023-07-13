// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int maxProfit(std::vector<int>& prices, int fee) {
    int n = prices.size();
    if (n <= 1)
        return 0;
    
    int buy = -prices[0];   // 当前持有股票的最大收益
    int sell = 0;           // 当前不持有股票的最大收益
    
    for (int i = 1; i < n; ++i) {
        int prev_buy = buy;
        int prev_sell = sell;
        
        // 在第 i 天选择买入或者不买入
        buy = std::max(prev_buy, prev_sell - prices[i]);
        
        // 在第 i 天选择卖出或者不卖出
        sell = std::max(prev_sell, prev_buy + prices[i] - fee);
    }
    
    return sell;    // 返回最终的最大收益
}

int main() {
    std::vector<int> prices {1, 3, 2, 8, 4, 9};
    std::cout << "Max profit: " << maxProfit(prices, 2) << std::endl;
    
    std::vector<int> prices2 {1, 3, 7, 5, 10, 3};
    std::cout << "Max profit: " << maxProfit(prices2, 3) << std::endl;
    
    return 0;
}