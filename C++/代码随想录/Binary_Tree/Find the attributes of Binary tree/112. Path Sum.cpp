// 112. Path Sum
// https://leetcode.com/problems/path-sum/
// clang++ 112.\ Path\ Sum.cpp -std=c++17
#include "../../printUtils.hpp"

bool hasPathSum(TreeNode<int>* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) ||
            hasPathSum(root->right, sum - root->val);
}

int main() {
    TreeNode<int>* root = buildTree({5,4,8,11,-1,13,4,7,2,-1,-1,-1,1}, -1);
    std::cout<< std::boolalpha << hasPathSum(root, 22) << std::endl;
    deleteTree(root);

    return 0;
}
