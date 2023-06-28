// 18. 4Sum
// https://leetcode.com/problems/4sum/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            // 跳过重复的元素
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n - 2; ++j) {
                // 跳过重复的元素
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum < target) {
                        ++left;
                    } else if (sum > target) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // 跳过重复的元素
                        while (left < right && nums[left] == nums[left + 1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            --right;
                        }

                        ++left;
                        --right;
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

