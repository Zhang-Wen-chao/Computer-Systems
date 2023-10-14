// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/
// g++ 572.\ Subtree\ of\ Another\ Tree.cpp -std=c++17
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

template <typename T>
bool isSubtree(TreeNode<T>* s, TreeNode<T>* t) {
    if (s == nullptr) {
        return false;
    }
    if (isSameTree(s, t)) {
        return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main() {
    TreeNode<int>* s = buildTree({3, 4, 5, 1, 2}, -1);
    TreeNode<int>* t = buildTree({4, 1, 2}, -1);

    std::cout << std::boolalpha << isSubtree(s, t) << std::endl;

    return 0;
}