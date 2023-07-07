// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include "../../BinaryTreeUtils.hpp"

template <typename T>
void inorderTraversal(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result); // 递归遍历左子树
    result.push_back(root->val); // 将当前节点的值加入结果数组
    inorderTraversal(root->right, result); // 递归遍历右子树
}

template <typename T>
std::vector<T> inorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    inorderTraversal(root, result);
    return result;
}

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Inorder Traversal: ";
    printArray(inorderTraversal(root));

    return 0;
}
