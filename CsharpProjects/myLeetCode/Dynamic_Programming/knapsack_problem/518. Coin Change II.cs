// 518. Coin Change II
// https://leetcode.com/problems/coin-change-ii/

#include <iostream>
#include <vector>

int change(int amount, std::vector<int>& coins) {
    int n = coins.size();
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    
    return dp[amount];
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 5},
        {2},
        {10}
    };
    std::vector<int> amount = {5, 3, 10};

    for (int i = 0; i < testCases.size(); i++) {
        int result = change(amount[i], testCases[i]);

        std::cout << "For the coins: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the number of combinations to form the amount " << amount[i] 
                  << " is " << result << "." << std::endl;
    }

    return 0;
}
