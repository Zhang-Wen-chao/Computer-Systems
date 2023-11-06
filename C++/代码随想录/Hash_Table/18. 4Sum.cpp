// 18. 4Sum
// https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        if (nums.size() < 4) return result;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates
            
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;  // Skip duplicates
                
                int twoSumTarget = target - nums[i] - nums[j];
                int left = j + 1, right = nums.size() - 1;
                
                while (left < right) {
                    if (nums[left] + nums[right] == twoSumTarget) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left-1]) left++;  // Skip duplicates
                        while (left < right && nums[right] == nums[right+1]) right--;  // Skip duplicates
                    } else if (nums[left] + nums[right] < twoSumTarget) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector<std::vector<int>> result = sol.fourSum(nums, target);

    // 输出结果
    for (const auto& quadruplet : result) {
        for (int num : quadruplet) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

