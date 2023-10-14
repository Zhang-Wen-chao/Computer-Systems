// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/
// clang++ 226.\ Invert\ Binary\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template <typename T>
TreeNode<T>* invertTree(TreeNode<T>* root) {
    if (root == nullptr) return nullptr;

    TreeNode<T>* left = invertTree(root->left);
    TreeNode<T>* right = invertTree(root->right);

    root->left = right;
    root->right = left;
    
    return root;
}

int main() {
    TreeNode<int>* root = buildTree({4, 2, 7, 1, 3, 6, 9}, -1);
    TreeNode<int>* inverted = invertTree(root);

    std::cout << "Inverted binary tree:" << std::endl;
    printArray(levelOrder(inverted));

    return 0;
}