// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

#include "../BinaryTreeUtils.hpp"

TreeNode<int>* invertTree(TreeNode<int>* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode<int>* left = invertTree(root->left);
    TreeNode<int>* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main() {
    TreeNode<int>* root = buildTree({4, 2, 7, 1, 3, 6, 9}, -1);
    TreeNode<int>* inverted = invertTree(root);

    std::cout << "Inverted binary tree:" << std::endl;
    std::vector<std::vector<int>> result = levelOrder(inverted);
    printArray(result);
    return 0;
}