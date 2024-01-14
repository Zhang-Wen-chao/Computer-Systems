// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/
// clang++ 199.\ Binary\ Tree\ Right\ Side\ View.cpp  -std=c++17

#include "../../../printUtils.hpp"
#include <vector>

template <typename T>
std::vector<T> rightSideView(TreeNode<T>* root) {
    std::vector<T> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode<T>* curr = q.front();
            q.pop();

            if (i == size - 1) {
                result.push_back(curr->val);
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            }
        }
    return result;
}

int main() {
    TreeNode<int>* root = buildTree({1, 2, 3, -1, 5, -1, 4}, -1);
    std::cout << "Right Side View of Binary Tree:" << std::endl;
    printArray(rightSideView(root));
    deleteTree(root);
    
    return 0;
}
