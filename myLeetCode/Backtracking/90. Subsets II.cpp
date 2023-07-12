// LeetCode 90. Subsets II
// https://leetcode.com/problems/subsets-ii/

#include <algorithm>
#include "../printUtils.hpp"

// 一个简单的递归函数，用来生成所有子集
void generateSubsets(std::vector<int>& nums, int index, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    // 将当前子集加入结果中
    result.push_back(current);
    // 从当前索引开始遍历数组中的元素
    for (int i = index; i < nums.size(); i++) {
        // 如果当前元素和前一个元素相同，且前一个元素没有被包含在当前子集中，那么跳过当前元素，避免重复子集
        if (i > index && nums[i] == nums[i - 1]) {
            continue;
        }
        // 包含当前元素，将其加入当前子集，然后递归到下一个元素
        current.push_back(nums[i]);
        generateSubsets(nums, i + 1, current, result);
        // 回溯，将当前元素从当前子集中移除，恢复原状
        current.pop_back();
    }
}

// 主函数，调用递归函数生成所有子集
std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    // 结果数组，用来存放所有子集
    std::vector<std::vector<int>> result;
    // 当前子集，用来存放每个子集的元素
    std::vector<int> current;
    // 先对数组进行排序，方便去重
    std::sort(nums.begin(), nums.end());
    // 从第一个元素开始递归
    generateSubsets(nums, 0, current, result);
    // 返回结果数组
    return result;
}

// 主函数，测试几个例子
int main() {
    std::vector<int> nums1 = {1, 2, 2};
    printSet(subsetsWithDup(nums1));
    std::cout << "===============" <<std::endl;

    std::vector<int> nums2 = {0};
    printSet(subsetsWithDup(nums2));
    std::cout << "===============" <<std::endl;

    std::vector<int> nums3 = {};
    printSet(subsetsWithDup(nums3));

    return 0;
}
