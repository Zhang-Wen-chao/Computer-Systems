// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include "../../printUtils.hpp"

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Preorder Traversal: ";
    printArray(preorderTraversal(root));
    deleteTree(root);

    return 0;
}
