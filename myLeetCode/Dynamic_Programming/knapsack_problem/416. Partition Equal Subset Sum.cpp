// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <numeric> // 包含 accumulate 函数的头文件

bool canPartition(std::vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    
    if (sum % 2 != 0) {
        return false;
    }
    
    int target = sum / 2;
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    
    return dp[n][target];
}

int main() {
    std::vector<std::vector<int>> testCases = {
        {1, 5, 11, 5},
        {1, 2, 3, 5},
        {1, 2, 3, 4, 5, 6, 7}
    };

    for (auto& testCase : testCases) {
        bool result = canPartition(testCase);
        
        std::cout << "For the array: [";
        for (int i = 0; i < testCase.size(); i++) {
            std::cout << testCase[i];
            if (i != testCase.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], ";
        
        std::cout << (result ? "Partition is possible" : "Partition is not possible") << "." << std::endl;
    }

    return 0;
}
