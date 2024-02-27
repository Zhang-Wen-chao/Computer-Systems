// 404. Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/
// clang++ 404.\ Sum\ of\ Left\ Leaves.cpp -std=c++17
#include "../../printUtils.hpp"

template <typename T>
T sumOfLeftLeaves(TreeNode<T>* root) {
    if (root == nullptr)
        return T();

    T sum = T();
    if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
        sum += root->left->val;

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    TreeNode<int>* root1 = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    int sum1 = sumOfLeftLeaves(root1);
    std::cout << "Sum of left leaves: " << sum1 << std::endl;
    deleteTree(root1);

    TreeNode<double>* root2 = buildTree({3.0, 9.346, 20.0, -1.0, -1.0, 15.0, 7.0}, -1.0);
    double sum2 = sumOfLeftLeaves(root2);
    std::cout << "Sum of left leaves: " << sum2 << std::endl;
    deleteTree(root2);

    return 0;
}
