// LeetCode 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

#include <algorithm>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::sort(nums.begin(), nums.end()); // 先对数组进行排序，方便去重
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 2};
    printSet(Solution().subsetsWithDup(nums1));

    std::vector<int> nums2 = {0};
    printSet(Solution().subsetsWithDup(nums2));

    return 0;
}
