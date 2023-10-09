// 39. Combination Sum
// https://leetcode.com/problems/combination-sum/

#include "../printUtils.hpp"
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans; // 存储最终结果
        std::vector<int> path; // 存储当前路径
        std::sort(candidates.begin(), candidates.end()); // 先对候选数组排序，方便剪枝
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
            path.push_back(candidates[i]); // 将当前数字加入到路径中
            backtrack(candidates, target - candidates[i], i, ans, path); // 递归搜索，注意下一层的起始数字是i，因为可以重复使用同一个数字
            path.pop_back(); // 回溯，将当前数字从路径中移除
        }
    }
};

int main(){
    std::vector<int> candidates = {2, 3, 6, 7};
    printArray(Solution().combinationSum(candidates, 7));

    return 0;
}