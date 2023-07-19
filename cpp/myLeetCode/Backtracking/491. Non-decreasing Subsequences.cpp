// 491. Non-decreasing Subsequences
// https://leetcode.com/problems/non-decreasing-subsequences/

#include <unordered_set>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> temp;
        backtrack(nums, 0, temp, ans);
        return ans;
    }

private:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& temp, std::vector<std::vector<int>>& ans) {
        if (temp.size() > 1) {
            ans.push_back(temp);
        }
        std::unordered_set<int> seen;
        for (int i = start; i < nums.size(); i++) {
            // skip duplicate elements
            if (seen.count(nums[i])) continue;
            // only append nums[i] if temp is empty or non-decreasing
            if (temp.empty() || nums[i] >= temp.back()) {
                temp.push_back(nums[i]);
                seen.insert(nums[i]);
                backtrack(nums, i + 1, temp, ans);
                temp.pop_back();
            }
        }
    }
};

int main() {
    std::vector<int> nums1 = {4, 6, 7, 7};
    printSet(Solution().findSubsequences(nums1));

    return 0;
}