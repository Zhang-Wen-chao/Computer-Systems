// 47. Permutations II
// https://leetcode.com/problems/permutations-ii/

#include <algorithm>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        std::vector<int> temp;
        std::vector<bool> used(nums.size(), false);
        backtrack(nums, used, temp, result);
        return result;
    }
    
private:
    void backtrack(std::vector<int>& nums, std::vector<bool>& used, std::vector<int>& temp, std::vector<std::vector<int>>& result) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
                continue;
            }
            
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used, temp, result);
            temp.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    std::vector<int> nums1 = {1, 1, 2};
    printSet(Solution().permuteUnique(nums1));

    return 0;
}