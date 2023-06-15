// 714. Best Time to Buy and Sell Stock with Transaction Fee
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] -= prices[0]; // 持股票
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    // create an instance of Solution class
    Solution sol;

    // create a vector of test prices and a test fee
    // vector<int> prices {1,3,2,8,4,9};
    // int fee = 2;
    vector<int> prices {1,3,7,5,10,3};
    int fee = 3;
    // call the maxProfit method and print the result
    int result = sol.maxProfit(prices, fee);
    cout << "The maximum profit is " << result << endl;

    return 0;
}