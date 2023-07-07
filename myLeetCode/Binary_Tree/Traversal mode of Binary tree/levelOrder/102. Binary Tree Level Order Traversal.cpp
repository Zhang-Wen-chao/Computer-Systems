// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include "../../BinaryTreeUtils.hpp"

int main() {
    std::vector<int> levelOrderValues = {3, 9, 20, -1, -1, 15, 7};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);
    std::vector<std::vector<int>> result = levelOrder(root, 2);
    printArray(result);

    return 0;
}
