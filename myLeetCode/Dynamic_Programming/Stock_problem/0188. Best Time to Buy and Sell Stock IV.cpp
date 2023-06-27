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
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int j = 1; j < 2 * k; j += 2) {
            dp[0][j] = -prices[0];
        }
        for (int i = 1;i < prices.size(); i++) {
            for (int j = 0; j < 2 * k - 1; j += 2) {
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] - prices[i]);
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};

int main() {
    // test case
    Solution sol;
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    cout << "The maximum profit is: " << sol.maxProfit(k, prices) << endl;
    return 0;
}