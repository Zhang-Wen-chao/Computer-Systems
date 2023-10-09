// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include "../../printUtils.hpp"



int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Inorder Traversal: ";
    printArray(inorderTraversal(root));
    deleteTree(root);

    return 0;
}
