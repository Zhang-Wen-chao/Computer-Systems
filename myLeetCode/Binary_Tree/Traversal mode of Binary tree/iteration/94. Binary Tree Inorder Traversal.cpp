// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/


#include "../../BinaryTreeUtils.hpp"
#include <stack>

std::vector<int> inorderTraversal(TreeNode<int>* root) {
    std::vector<int> result;
    std::stack<TreeNode<int>*> stk;

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
    std::vector<int> levelOrderValues = {1, 2, 3, 4, -1, 5, 6};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<int> result = inorderTraversal(root);

    std::cout << "Inorder traversal: ";
    printArray(result);

    return 0;
}
