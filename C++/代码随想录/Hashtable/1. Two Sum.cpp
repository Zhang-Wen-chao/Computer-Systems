// 1. Two Sum
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numToIndex.find(complement) != numToIndex.end()) {
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i;
        }
        return {};  // 返回空数组，实际上这种情况在题目中不会发生，因为题目保证有解。
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    std::vector<int> res = sol.twoSum(nums, target);
    for (int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
