// 222. Count Complete Tree Nodes
// https://leetcode.com/problems/count-complete-tree-nodes/
// clang++ 222.\ Count\ Complete\ Tree\ Nodes.cpp -std=c++17
#include "../../printUtils.hpp"

template <typename T>
int countNodes(TreeNode<T>* root) {
    if (root == nullptr) return 0;
    
    int leftHeight = 0, rightHeight = 0;
    TreeNode<T>* leftNode = root, *rightNode = root;
    
    while (leftNode) {
        leftHeight++;
        leftNode = leftNode->left;
    }
    
    while (rightNode) {
        rightHeight++;
        rightNode = rightNode->right;
    }
    
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, 5, 6}, -1);
    std::cout << "Number of nodes in the binary tree: " << countNodes(root) << std::endl;
    deleteTree(root);
    
    return 0;
}

