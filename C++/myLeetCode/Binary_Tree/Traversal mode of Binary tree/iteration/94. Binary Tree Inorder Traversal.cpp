// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

// clang++ 94.\ Binary\ Tree\ Inorder\ Traversal.cpp -std=c++17

#include "../../../printUtils.hpp"
#include <stack>
#include <vector>

template <typename T>
std::vector<T> inOrderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    std::stack<TreeNode<T>*> stk;

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
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "Inorder traversal: ";
    printArray(inOrderTraversal(root));
    deleteTree(root);
    
    return 0;
}
