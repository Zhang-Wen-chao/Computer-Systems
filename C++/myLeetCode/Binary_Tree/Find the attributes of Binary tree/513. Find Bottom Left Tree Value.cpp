// 513. Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/
// clang++ 513.\ Find\ Bottom\ Left\ Tree\ Value.cpp -std=c++17
#include "../../printUtils.hpp"

template <typename T>
int findBottomLeftValue(TreeNode<T>* root) {
    std::queue<TreeNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (root->right) {
            q.push(root->right);
        }
        if (root->left) {
            q.push(root->left);
        }
    }
    return root->val;
}

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6, -1, -1, 7}, -1);
    int result = findBottomLeftValue(root);
    std::cout << "Bottom left value: " << result << std::endl;
    deleteTree(root);

    return 0;
}
