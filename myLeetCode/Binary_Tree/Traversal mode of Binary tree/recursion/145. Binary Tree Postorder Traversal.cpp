// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include "../../printUtils.hpp"

template <typename T>
void postorderTraversal(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    postorderTraversal(root->left, result); // 递归遍历左子树
    postorderTraversal(root->right, result); // 递归遍历右子树
    result.push_back(root->val); // 将当前节点的值加入结果数组
}

template <typename T>
std::vector<T> postorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    postorderTraversal(root, result);
    return result;
}

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Postorder Traversal: ";
    printArray(postorderTraversal(root));
    deleteTree(root);
    
    return 0;
}
