// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include "../BinaryTreeUtils.hpp"
#include <climits>

template <typename T>
int minDepth(TreeNode<T>* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr) return 1;
    
    int leftDepth = root->left ? minDepth(root->left) : INT_MAX;
    int rightDepth = root->right ? minDepth(root->right) : INT_MAX;
    
    return 1 + std::min(leftDepth, rightDepth);
}

int main() {
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    std::cout << "Minimum depth of the binary tree: " << minDepth(root) << std::endl;

    return 0;
}
