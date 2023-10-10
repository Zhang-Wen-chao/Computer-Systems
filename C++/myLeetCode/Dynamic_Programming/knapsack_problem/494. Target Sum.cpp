// 494. Target Sum
// https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
#include <numeric> // 包含 accumulate 函数的头文件

int findTargetSumWays(std::vector<int>& nums, int target) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);

    if (target > sum || (target + sum) % 2 != 0) {
        return 0;
    }
    
    int subsetSum = (target + sum) / 2;
    int n = nums.size();
    std::vector<int> dp(subsetSum + 1, 0);
    dp[0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = subsetSum; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    
    return dp[subsetSum];
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 1, 1, 1, 1},
        {1, 2, 3, 4, 5},
        {1, 3, 4, 5, 2}
    };
    std::vector<int> target = {3, 5, 6};

    for (int i = 0; i < testCases.size(); i++) {
        int result = findTargetSumWays(testCases[i], target[i]);
        std::cout << "For the array: [";
        for (int j = 0; j < testCases[i].size(); j++) {
            std::cout << testCases[i][j];
            if (j != testCases[i].size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the number of ways to achieve the target sum of " << target[i] << " is " << result << "." << std::endl;
    }

    return 0;
}