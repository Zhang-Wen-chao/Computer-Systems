// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include "../../printUtils.hpp"

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Postorder Traversal: ";
    printArray(postorderTraversal(root));
    deleteTree(root);

    return 0;
}
