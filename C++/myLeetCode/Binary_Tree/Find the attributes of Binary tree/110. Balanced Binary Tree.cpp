// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/
// clang++ 110.\ Balanced\ Binary\ Tree.cpp -std=c++17
#include <cmath>
#include "../../printUtils.hpp"

template <typename T>
class Solution {
public:
    bool isBalanced(TreeNode<T>* root) {
        if (root == nullptr) {
            return true;
        }

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if (std::abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode<T>* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + std::max(leftHeight, rightHeight);
    }
};

int main() {
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    std::cout << "Is the binary tree balanced? " << std::boolalpha << Solution<int>().isBalanced(root) << std::endl;
    deleteTree(root);
    
    return 0;
}
