// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/


// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// clang++ 94.\ Binary\ Tree\ Inorder\ Traversal.cpp -std=c++17

#include "../../../printUtils.hpp"

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Inorder Traversal: ";
    printArray(inorderTraversal(root));

    std::cout << "Preorder Traversal: ";
    printArray(preorderTraversal(root));

    std::cout << "Postorder Traversal: ";
    printArray(postorderTraversal(root));
    
    deleteTree(root);

    return 0;
}
