// 78. Subsets
// https://leetcode.com/problems/subsets/

#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        if (index >= nums.size()) {
            result.push_back(current);
            return;
        }

        backtrack(nums, index + 1, current, result);

        current.push_back(nums[index]);
        backtrack(nums, index + 1, current, result);
        current.pop_back();
    }
};

int main() {
    std::vector<int> nums1 = {1, 2, 3};
    printSet(Solution().subsets(nums1));
    
    std::vector<int> nums2 = {0};
    printSet(Solution().subsets(nums2));

    return 0;
}
