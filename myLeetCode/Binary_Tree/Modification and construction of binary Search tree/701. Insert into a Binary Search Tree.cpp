// 701. Insert into a Binary Search Tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/


#include <iostream>
#include <climits>

#include "../BinaryTreeUtils.hpp"


void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    std::vector<int> data = {1, 2, 3, INT_MAX, 4, 5, 6, 7, INT_MAX};

    TreeNode* root = buildTree(data);

    std::cout << "Inorder Traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
