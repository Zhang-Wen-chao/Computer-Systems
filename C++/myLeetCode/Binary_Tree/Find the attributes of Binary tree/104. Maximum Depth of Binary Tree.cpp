// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// clang++ 104.\ Maximum\ Depth\ of\ Binary\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template <typename T>
int maxDepth(TreeNode<T>* root) {
    if (root == nullptr) return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return 1 + std::max(leftDepth, rightDepth);
}

int main() {
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    std::cout << "Maximum depth of the binary tree: " << maxDepth(root) << std::endl;
    deleteTree(root);
    
    return 0;
}