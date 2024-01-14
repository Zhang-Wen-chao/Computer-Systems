// 700. Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/
// clang++ 700.\ Search\ in\ a\ Binary\ Search\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template <typename T>
TreeNode<T>* searchBST(TreeNode<T>* root, T val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (root->val > val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

int main() {
    TreeNode<int>* root = buildTree({4, 2, 7, 1, 3}, -1);
    int target = 2;
    TreeNode<int>* node = searchBST(root, target);

    std::cout << "The subtree rooted with the node with value " << target << " is: " << std::endl;
    printArray(levelOrder(node));

    return 0;
}