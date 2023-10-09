// 40. Combination Sum II
// https://leetcode.com/problems/combination-sum-ii/

#include <algorithm>
#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans; // 存储最终结果
        std::vector<int> path; // 存储当前路径
        std::sort(candidates.begin(), candidates.end()); // 先对候选数组排序，方便剪枝和去重
        backtrack(candidates, target, 0, ans, path); // 从第0个候选数字开始搜索
        return ans;
    }

private:
    void backtrack(std::vector<int>& candidates, int target, int start, std::vector<std::vector<int>>& ans, std::vector<int>& path) {
        if (target == 0) { // 如果目标值为0，说明找到一个满足条件的组合
            ans.push_back(path); // 加入到结果中
            return;
        }
        for (int i = start; i < candidates.size(); i++) { // 遍历候选数组
            if (target - candidates[i] < 0) break; // 剪枝，如果目标值减去当前数字为负数，说明后面的数字都不满足条件，直接跳出循环
            if (i > start && candidates[i] == candidates[i - 1]) continue; // 去重，如果当前数字和前一个数字相同，且前一个数字没有被使用过，说明当前数字会产生重复的组合，直接跳过
            path.push_back(candidates[i]); // 将当前数字加入到路径中
            backtrack(candidates, target - candidates[i], i + 1, ans, path); // 递归搜索，注意下一层的起始数字是i+1，因为不能重复使用同一个数字
            path.pop_back(); // 回溯，将当前数字从路径中移除
        }
    }
};


int main() {
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    printArray(Solution().combinationSum2(candidates, 8));

    std::cout << "===============" <<std::endl;

    std::vector<int> candidates2 = {2,5,2,1,2};
    printArray(Solution().combinationSum2(candidates2, 5));

    return 0;
}
