// 46. Permutations
// https://leetcode.com/problems/permutations/

#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(result, nums, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& nums, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[i], nums[start]);
            backtrack(result, nums, start + 1);
            std::swap(nums[i], nums[start]);
        }
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};
    printSet(Solution().permute(nums));

    return 0;
}
