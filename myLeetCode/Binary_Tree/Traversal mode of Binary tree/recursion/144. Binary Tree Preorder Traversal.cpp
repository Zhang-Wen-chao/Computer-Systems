// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include "../../printUtils.hpp"

template <typename T>
void preorderTraversal(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    result.push_back(root->val); // 将当前节点的值加入结果数组
    preorderTraversal(root->left, result); // 递归遍历左子树
    preorderTraversal(root->right, result); // 递归遍历右子树
}

template <typename T>
std::vector<T> preorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    preorderTraversal(root, result);
    return result;
}

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Preorder Traversal: ";
    printArray(preorderTraversal(root));
    deleteTree(root);
    
    return 0;
}
