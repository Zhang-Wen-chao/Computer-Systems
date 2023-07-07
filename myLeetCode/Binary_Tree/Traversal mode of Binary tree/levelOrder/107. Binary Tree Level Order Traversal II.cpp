// 107. Binary Tree Level Order Traversal II
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


#include "../../BinaryTreeUtils.hpp"
#include <algorithm>

std::vector<std::vector<int>> levelOrderBottom(TreeNode<int>* root) {
    std::vector<std::vector<int>> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode<int>* curr = q.front();
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
    std::vector<int> levelOrderValues = {3, 9, 20, -1, -1, 15, 7};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<std::vector<int>> result = levelOrderBottom(root);

    std::cout << "Level Order Traversal (Bottom-Up):" << std::endl;
    printArray(result);

    return 0;
}
