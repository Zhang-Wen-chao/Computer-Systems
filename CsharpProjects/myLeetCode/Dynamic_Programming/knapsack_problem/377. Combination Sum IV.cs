// 377. Combination Sum IV
// https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <vector>

int combinationSum4(std::vector<int>& nums, int target) {
    std::vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    
    return dp[target];
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3},
        {9},
        {2, 5, 9},
        {1, 2, 3, 4, 5}
    };
    std::vector<int> targets = {4, 3, 18, 7};

    for (int i = 0; i < testCases.size(); i++) {
        int result = combinationSum4(testCases[i], targets[i]);

        std::cout << "For the array: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the number of combinations to form the target sum " << targets[i] 
                  << " is " << result << "." << std::endl;
    }

    return 0;
}