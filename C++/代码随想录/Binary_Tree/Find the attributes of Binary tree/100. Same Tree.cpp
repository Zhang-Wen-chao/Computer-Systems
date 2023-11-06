// 100. Same Tree
// https://leetcode.com/problems/same-tree/
// clang++ 100.\ Same\ Tree.cpp -std=c++17

#include "../../printUtils.hpp"

template <typename T>
bool isSameTree(TreeNode<T>* p, TreeNode<T>* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode<int>* p = buildTree({1, 2, 3}, -1);
    TreeNode<int>* q = buildTree({1, 2, 3}, -1);
    
    std::cout << std::boolalpha << isSameTree(p, q) << std::endl;

    deleteTree(p);
    deleteTree(q);
    
    return 0;
}
