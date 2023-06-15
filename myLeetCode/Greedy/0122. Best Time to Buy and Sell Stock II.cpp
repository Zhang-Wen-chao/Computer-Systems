// 122. Best Time to Buy and Sell Stock II
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// **收集正利润的区间，就是股票买卖的区间，而我们只需要关注最终利润，不需要记录区间**。
// 那么只收集正利润就是贪心所贪的地方！
// **局部最优：收集每天的正利润，全局最优：求得最大利润**。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); i++) {
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
};

int main() {
    // create an instance of Solution class
    Solution sol;

    // create a vector of test prices
    vector<int> prices {7,1,5,3,6,4};

    // call the maxProfit method and print the result
    int result = sol.maxProfit(prices);
    cout << "The maximum profit is " << result << endl;

    return 0;
}