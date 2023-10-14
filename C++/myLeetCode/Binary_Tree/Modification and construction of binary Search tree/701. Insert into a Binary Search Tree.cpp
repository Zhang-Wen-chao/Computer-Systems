// 701. Insert into a Binary Search Tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/
// clang++ 701.\ Insert\ into\ a\ Binary\ Search\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
TreeNode<T>* insertIntoBST(TreeNode<T>* root, T val) {
    if (!root) return new TreeNode<T>(val);
    if (root->val > val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

int main() {
    TreeNode<int>* root = buildTree({4, 2, 7, 1, 3}, -1);
    TreeNode<int>* result = insertIntoBST(root, 5);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result));


    TreeNode<int>* root2 = buildTree({40, 20, 60, 10, 30, 50, 70}, -1);
    TreeNode<int>* result2 = insertIntoBST(root2, 25);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result2));


    TreeNode<int>* root3 = buildTree({4, 2, 7, 1, 3, -1, -1, -1, -1, -1, -1}, -1);
    TreeNode<int>* result3 = insertIntoBST(root3, 5);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result3));

    return 0;
}
