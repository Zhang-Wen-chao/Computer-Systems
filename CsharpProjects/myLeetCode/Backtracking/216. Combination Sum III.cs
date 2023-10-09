// 216. Combination Sum III
// https://leetcode.com/problems/combination-sum-iii/

#include "../printUtils.hpp"

class Solution {
public:
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> result; // 存储最终结果
        std::vector<int> path; // 存储当前路径
        backtrack(k, n, 1, result, path); // 从1开始搜索
        return result;
    }

private:
    void backtrack(int k, int n, int start, std::vector<std::vector<int>>& result, std::vector<int>& path) {
        if (k == 0 && n == 0) { // 找到一个满足条件的组合
            result.push_back(path); // 加入到结果中
            return;
        }
        if (k < 0 || n < 0) return; // 剪枝，如果k或n为负数，说明不满足条件
        for (int i = start; i <= 9; i++) { // 遍历1到9的数字
            path.push_back(i); // 将当前数字加入到路径中
            backtrack(k - 1, n - i, i + 1, result, path); // 递归搜索，注意下一层的起始数字是i+1，避免重复使用
            path.pop_back(); // 回溯，将当前数字从路径中移除
        }
    }
};

int main() {
    printSet(Solution().combinationSum3(3, 7));

    printSet(Solution().combinationSum3(3, 9));

    return 0;
}
