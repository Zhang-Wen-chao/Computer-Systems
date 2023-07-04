// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include <stack>

std::vector<int> preorderTraversal(TreeNode<int>* root) {
    std::vector<int> result;
    std::stack<TreeNode<int>*> stk;

    while (root != nullptr || !stk.empty()) {
        if (root != nullptr) {
            result.push_back(root->val);
            stk.push(root->right);
            root = root->left;
        } else {
            root = stk.top();
            stk.pop();
        }
    }

    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, 4, -1, 5, 6};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<int> result = preorderTraversal(root);

    std::cout << "Preorder traversal: ";
    printArray(result);

    return 0;
}
