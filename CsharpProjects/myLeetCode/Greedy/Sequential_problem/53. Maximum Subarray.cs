// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>

int maxSubArray(const std::vector<int>& nums) {
    int currentMax = 0;
    int globalMax = 0;

    for (const auto& num : nums) {
        currentMax = std::max(num, currentMax + num);
        globalMax = std::max(globalMax, currentMax);
    }

    return globalMax;
}

int main() {
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << maxSubArray(nums) << std::endl;

    std::vector<int> nums2 = {1};
    std::cout << maxSubArray(nums2) << std::endl;

    std::vector<int> nums3 = {5,4,-1,7,8};
    std::cout << maxSubArray(nums3) << std::endl;

    return 0;
}