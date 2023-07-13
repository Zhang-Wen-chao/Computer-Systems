// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// **收集正利润的区间，就是股票买卖的区间，而我们只需要关注最终利润，不需要记录区间**。
// 那么只收集正利润就是贪心所贪的地方！
// **局部最优：收集每天的正利润，全局最优：求得最大利润**。

#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int result = 0;
    for (int i = 1; i < prices.size(); i++) {
        result += std::max(prices[i] - prices[i - 1], 0);
    }
    return result;
}

int main() {
    std::vector<int> prices {7,1,5,3,6,4};
    std::cout << "The maximum profit is " << maxProfit(prices) << std::endl;

    std::vector<int> prices2 {1,2,3,4,5};
    std::cout << "The maximum profit is " << maxProfit(prices2) << std::endl;

    std::vector<int> prices3 {7,6,4,3,1};
    std::cout << "The maximum profit is " << maxProfit(prices3) << std::endl;

    return 0;
}