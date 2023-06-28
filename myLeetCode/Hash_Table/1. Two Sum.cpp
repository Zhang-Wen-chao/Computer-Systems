// 1. Two Sum
// https://leetcode.cn/problems/two-sum/
#include <unordered_map>
#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement) != 0) {
                return { map[complement], i };
            }
            map[nums[i]] = i;
        }
        return {};
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