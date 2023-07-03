// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include "../../BinaryTreeUtils.hpp"

void inorderTraversal(TreeNode<int>* root, std::vector<int>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result); // 递归遍历左子树
	result.push_back(root->val); // 将当前节点的值加入结果数组
    inorderTraversal(root->right, result); // 递归遍历右子树
}

std::vector<int> inorderTraversal(TreeNode<int>* root) {
    std::vector<int> result;
    inorderTraversal(root, result);
    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, 4, -1, 5, 6};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<int> result = inorderTraversal(root);

    std::cout << "Inorder Traversal: ";
    printArray(result);

    return 0;
}
