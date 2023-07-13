// 1049. Last Stone Weight II
//  https://leetcode.com/problems/last-stone-weight-ii/

#include <iostream>
#include <vector>
#include <numeric> // 包含 accumulate 函数的头文件

int lastStoneWeightII(std::vector<int>& stones) {
    int sum = std::accumulate(stones.begin(), stones.end(), 0);

    int target = sum / 2;
    std::vector<int> dp(target + 1, 0);
    
    for (int stone : stones) {
        for (int i = target; i >= stone; i--) {
            dp[i] = std::max(dp[i], dp[i - stone] + stone);
        }
    }
    
    return sum - 2 * dp[target];
}

int main() {
    std::vector<std::vector<int>> testCases = {{2, 7, 4, 1, 8, 1}, {31, 26, 33, 21, 40}};
    for (auto& testCase: testCases) {
        std::cout << "For the array: [";
        for (int i = 0; i < testCase.size(); i++) {
            std::cout << testCase[i];
            if (i != testCase.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "], the smallest possible difference between the sum of two subsets of the array is " << lastStoneWeightII(testCase) << "." << std::endl;
    }

    return 0;
}