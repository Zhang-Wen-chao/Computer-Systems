// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

// clang++ 107.\ Binary\ Tree\ Level\ Order\ Traversal\ II.cpp  -std=c++17

#include "../../../printUtils.hpp"
#include <algorithm>
#include <vector>

template <typename T>
std::vector<std::vector<T>> levelOrderBottom(TreeNode<T>* root) {
    std::vector<std::vector<T>> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<T> level;

        for (int i = 0; i < size; i++) {
            TreeNode<T>* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(level);
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main() {
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    std::cout << "Level Order Traversal (Bottom-Up):" << std::endl;
    printArray(levelOrderBottom(root));
    deleteTree(root);
    
    return 0;
}
