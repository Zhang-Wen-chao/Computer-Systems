// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include <iostream>
#include <stack>

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) {
        return result;
    }

    std::stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        result.push_back(node->val);

        // 先将右子树入栈，再将左子树入栈
        if (node->right != nullptr) {
            stk.push(node->right);
        }
        if (node->left != nullptr) {
            stk.push(node->left);
        }
    }

    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, 4, INT_MAX, 5, 6};
    TreeNode* root = buildTree(levelOrderValues);

    std::vector<int> result = preorderTraversal(root);

    std::cout << "Preorder traversal: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
