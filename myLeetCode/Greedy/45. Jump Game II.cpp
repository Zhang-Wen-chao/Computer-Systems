// 45. Jump Game II
// https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>

int jump(std::vector<int>& nums) {
    int n = nums.size(), jumps = 0, currEnd = 0, maxReach = 0;
    if (n <= 1) 
        return 0;

    for (int i = 0; i < n - 1; ++i) {
        maxReach = std::max(maxReach, i + nums[i]);
        if (i == currEnd) {
            currEnd = maxReach;
            ++jumps;

            if (currEnd >= n - 1) {
                break;
            }
        }
    }

    return jumps;
}

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    std::cout << "Minimum number of jumps: " << jump(nums) << std::endl;

    std::vector<int> nums2 = {2, 3, 0, 1, 4};
    std::cout << "Minimum number of jumps: " << jump(nums2) << std::endl;

    return 0;
}
