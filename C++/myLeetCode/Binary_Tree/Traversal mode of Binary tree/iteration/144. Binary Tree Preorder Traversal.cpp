// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

// clang++ 144.\ Binary\ Tree\ Preorder\ Traversal.cpp -std=c++17

#include "../../../printUtils.hpp"
#include <stack>
#include <vector>

template <typename T>
std::vector<T> preOrderTraversal(TreeNode<T>* root) {
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
    std::cout << "Preorder traversal: ";
    printArray(preOrderTraversal(root));
    deleteTree(root);
    
    return 0;
}
