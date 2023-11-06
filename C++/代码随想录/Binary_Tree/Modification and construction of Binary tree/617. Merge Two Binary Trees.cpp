// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/
// clang++ 617.\ Merge\ Two\ Binary\ Trees.cpp -std=c++17
#include "../../printUtils.hpp"
/*
这个确实简洁，但是对内存的处理不好，或者说我还不会处理这种内存。
template <typename T>
TreeNode<T>* mergeTrees(TreeNode<T>* t1, TreeNode<T>* t2) {
    if (t1 == nullptr) return t2;
    if (t2 == nullptr) return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}
*/
template <typename T>
TreeNode<T>* mergeTrees(TreeNode<T>* t1, TreeNode<T>* t2) {
    if (t1 == nullptr && t2 == nullptr) 
        return nullptr;

    T val1 = (t1 == nullptr) ? 0 : t1->val;
    T val2 = (t2 == nullptr) ? 0 : t2->val;
    TreeNode<T>* root = new TreeNode<T>(val1 + val2);

    root->left = mergeTrees((t1 == nullptr) ? nullptr : t1->left, (t2 == nullptr) ? nullptr : t2->left);
    root->right = mergeTrees((t1 == nullptr) ? nullptr : t1->right, (t2 == nullptr) ? nullptr : t2->right);

    return root;
}

int main() {
    std::vector<int> nums1 = {1, 3, 2, 5};
    std::vector<int> nums2 = {2, 1, 3, -1, 4, -1, 7};
    TreeNode<int>* t1 = buildTree(nums1, -1);
    TreeNode<int>* t2 = buildTree(nums2, -1);

    TreeNode<int>*mergedTree = mergeTrees(t1, t2);

    std::cout << "The t1's address: " << std::endl;
    printTreeNodeAddresses(t1);

    std::cout << "The t2's address: " << std::endl;
    printTreeNodeAddresses(t2);

    std::cout << "The merged tree's address: " << std::endl;
    printTreeNodeAddresses(mergedTree);

    std::cout << "The merged tree: ";
    printArray(levelOrder(mergedTree));

    deleteTree(t1);
    deleteTree(t2);
    deleteTree(mergedTree);

    return 0;
}

