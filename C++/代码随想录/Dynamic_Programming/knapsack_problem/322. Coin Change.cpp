// 322. Coin Change
// https://leetcode.com/problems/coin-change/

#include <iostream>
#include <vector>
#include <limits>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i >= coins[j] && dp[i - coins[j]] != std::numeric_limits<int>::max()) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 5},
        {2},
        {1, 3, 4, 5}
    };
    std::vector<int> targets = {11, 3, 7};

    for (int i = 0; i < testCases.size(); i++) {
        int result = coinChange(testCases[i], targets[i]);

        std::cout << "For the coins: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the minimum number of coins needed to make the amount " << targets[i]
                  << " is " << result << "." << std::endl;
    }

    return 0;
}