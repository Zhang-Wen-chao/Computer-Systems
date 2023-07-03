// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/


#include "../../BinaryTreeUtils.hpp"
#include <stack>

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stk;

    while (root != nullptr || !stk.empty()) {
        if (root != nullptr) {
            stk.push(root);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
            result.push_back(root->val);
            root = root->right;
        }
    }

    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, 4, INT_MAX, 5, 6};
    TreeNode* root = buildTree(levelOrderValues);

    std::vector<int> result = inorderTraversal(root);

    std::cout << "Inorder traversal: ";
    print_1d(result);

    return 0;
}
