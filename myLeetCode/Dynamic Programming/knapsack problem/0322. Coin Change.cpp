// 322. Coin Change
// https://leetcode.com/problems/coin-change/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        // **dp[j]：凑足总额为j所需钱币的最少个数为dp[j]**
        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if(i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount = 10;
    cout << s.coinChange(coins, amount) << endl;
    return 0;
}