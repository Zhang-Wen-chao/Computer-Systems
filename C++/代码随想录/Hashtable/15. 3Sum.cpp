// 15. 3Sum
// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 3) return result;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates
            
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;  // Skip duplicates
                    while (left < right && nums[right] == nums[right+1]) right--;  // Skip duplicates
                } else if (nums[left] + nums[right] < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = sol.threeSum(nums);
    
    // 输出结果
    for (const auto& triplet : result) {
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
