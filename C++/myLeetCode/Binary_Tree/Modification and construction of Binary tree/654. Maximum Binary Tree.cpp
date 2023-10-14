// 654. Maximum Binary Tree
// https://leetcode.com/problems/maximum-binary-tree/
// 简而言之: 根结点是数组中最大的，左子树的结点是数组中max左侧数组最大的值，右子树是max右侧。

#include <algorithm>
#include "../../printUtils.hpp"

template <typename T>
TreeNode<T>* constructMaximumBinaryTree(const std::vector<T>& nums, int start, int end) {
    // 如果start大于end，说明区间为空，返回空指针
    if (start > end) return nullptr;
    // 找到区间内的最大值和对应的索引
    auto it = std::max_element(nums.begin() + start, nums.begin() + end + 1);
    int maxVal = *it;
    int maxIdx = it - nums.begin();
    // 以最大值为根节点，递归构造左右子树
    TreeNode<T>* root = new TreeNode<T>(maxVal);
    root->left = constructMaximumBinaryTree(nums, start, maxIdx - 1);
    root->right = constructMaximumBinaryTree(nums, maxIdx + 1, end);
    // 返回根节点
    return root;
}

int main(){
    std::vector<int> nums = {3, 2, 1, 6, 0, 5};
    TreeNode<int>* root = constructMaximumBinaryTree(nums, 0, nums.size() - 1);
    printArray(levelOrder(root));
    deleteTree(root);

    std::vector<int> nums2 = {3, 2, 1};
    TreeNode<int>* root2 = constructMaximumBinaryTree(nums2, 0, nums2.size() - 1);
    printArray(levelOrder(root2));
    deleteTree(root2);

    return 0;
}