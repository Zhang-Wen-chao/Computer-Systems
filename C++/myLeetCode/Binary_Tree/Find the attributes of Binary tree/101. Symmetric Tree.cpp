// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

// clang++ 101.\ Symmetric\ Tree.cpp -std=c++17

#include "../../printUtils.hpp"

template<typename T>
bool isSymmetricNodes(TreeNode<T>* left, TreeNode<T>* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }
    if (left == nullptr || right == nullptr || left->val != right->val) {
        return false;
    }
    return isSymmetricNodes(left->left, right->right) && isSymmetricNodes(left->right, right->left);
}

template<typename T>
bool isSymmetric(TreeNode<T>* root) {
    if (root == nullptr) return true;
    return isSymmetricNodes(root->left, root->right);
}

int main() {
    // TreeNode<int>* root = buildTree({1, 2, 2, 3, 4, 4, 3}, -1);
    TreeNode<int>* root = buildTree({1, 2, 2, -1, 3, -1, 3}, -1);
    std::cout << "Is the tree symmetric? " << (isSymmetric(root) ? "Yes" : "No") << std::endl;
    deleteTree(root);
    
    return 0;
}