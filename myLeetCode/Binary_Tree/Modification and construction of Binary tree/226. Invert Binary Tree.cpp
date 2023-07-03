// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

#include "../BinaryTreeUtils.hpp"

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}

int main() {
    TreeNode* root = buildTree({4, 2, 7, 1, 3, 6, 9});
    TreeNode* inverted = invertTree(root);

    std::cout << "Inverted binary tree:" << std::endl;
    std::vector<std::vector<int>> result = levelOrder(inverted);
    print_1d(result);
    return 0;
}