// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include "../../BinaryTreeUtils.hpp"

void postorderTraversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    postorderTraversal(root->left, result); // 递归遍历左子树
    postorderTraversal(root->right, result); // 递归遍历右子树
    result.push_back(root->val); // 将当前节点的值加入结果数组
}

std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    postorderTraversal(root, result);
    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, 4, INT_MAX, 5, 6};
    TreeNode* root = buildTree(levelOrderValues);

    std::vector<int> result = postorderTraversal(root);

    std::cout << "Postorder Traversal: ";
    print_1d(result);

    return 0;
}
