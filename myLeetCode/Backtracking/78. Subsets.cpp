// 78. Subsets
// https://leetcode.com/problems/subsets/

#include "../printUtils.hpp"

void generateSubsets(std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    // 如果索引超过了数组的长度，说明已经遍历完了所有元素，将当前子集加入结果中
    if (index >= nums.size()) {
        result.push_back(current);
        return;
    }
    // 两种选择：要么不包含当前元素，要么包含当前元素
    // 不包含当前元素，直接递归到下一个元素
    generateSubsets(nums, index + 1, current, result);
    // 包含当前元素，将其加入当前子集，然后递归到下一个元素
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    // 回溯，将当前元素从当前子集中移除，恢复原状
    current.pop_back();
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    generateSubsets(nums, 0, current, result);
    return result;
}

int main() {
    std::cout << "===============" <<std::endl;
    std::vector<int> nums1 = {1, 2, 3};
    printSet(subsets(nums1));
    std::cout << "===============" <<std::endl;
    std::vector<int> nums2 = {0};
    printSet(subsets(nums2));
    std::cout << "===============" <<std::endl;

    return 0;
}
