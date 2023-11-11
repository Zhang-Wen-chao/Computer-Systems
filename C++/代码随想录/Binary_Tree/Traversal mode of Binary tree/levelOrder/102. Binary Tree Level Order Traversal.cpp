// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/
// clang++ 102.\ Binary\ Tree\ Level\ Order\ Traversal.cpp -std=c++17

#include "../../../printUtils.hpp"

int main() {
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    printArray(levelOrder(root, 2));
    deleteTree(root);
    
    return 0;
}
