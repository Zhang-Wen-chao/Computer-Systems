// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include <stack>

template <typename T>
std::vector<T> preorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    std::stack<TreeNode<T>*> stk;

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
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::vector<int> result = preorderTraversal(root);

    std::cout << "Preorder traversal: ";
    printArray(result);

    return 0;
}
