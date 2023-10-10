// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../../Binary_Tree/BinaryTreeUtils.hpp"

class Solution {
public:
    int rob(TreeNode<int>* root) {
        std::unordered_map<TreeNode<int>*, int> memo;
        return robHelper(root, memo);
    }

private:
    int robHelper(TreeNode<int>* root, std::unordered_map<TreeNode<int>*, int>& memo) {
        if (root == nullptr) {
            return 0;
        }

        if (memo.count(root)) {
            return memo[root];
        }

        int robRoot = root->val;
        if (root->left != nullptr) {
            robRoot += robHelper(root->left->left, memo) + robHelper(root->left->right, memo);
        }
        if (root->right != nullptr) {
            robRoot += robHelper(root->right->left, memo) + robHelper(root->right->right, memo);
        }

        int skipRoot = robHelper(root->left, memo) + robHelper(root->right, memo);

        int maxAmount = std::max(robRoot, skipRoot);
        memo[root] = maxAmount;

        return maxAmount;
    }
};

int main() {
    std::vector<std::vector<int>> testCases = {
        {3, 2, 3, -1, 3, -1, 1},
        {3, 4, 5, 1, 3, -1, 1},
        {2},
        {}
    };

    for (int i = 0; i < testCases.size(); i++) {
        TreeNode<int>* root = buildTree(testCases[i], -1);

        std::cout << "For Test Case " << i + 1 << ", the maximum amount of money that can be robbed is " << Solution().rob(root) << "." << std::endl;

        deleteTree(root);
    }

    return 0;
}