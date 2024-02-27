// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
// clang++ 236.\ Lowest\ Common\ Ancestor\ of\ a\ Binary\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
TreeNode<T>* lowestCommonAncestor(TreeNode<T>* root, TreeNode<T>* p, TreeNode<T>* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    
    TreeNode<T>* left = lowestCommonAncestor(root->left, p, q);
    TreeNode<T>* right = lowestCommonAncestor(root->right, p, q);
    
    if (left != nullptr && right != nullptr) {
        return root;
    } else if (left != nullptr) {
        return left;
    } else {
        return right;
    }
}

int main() {
    TreeNode<int>* root = buildTree({3,5,1,6,2,0,8,-1,-1,7,4}, -1);
    // TreeNode<int>* p = root->left; // p = 5
    // TreeNode<int>* q = root->right; // q = 1
    TreeNode<int>* p = findNode(root, 5);  // 找到节点p
    TreeNode<int>* q = findNode(root, 1);  // 找到节点q

    TreeNode<int>* result = lowestCommonAncestor(root, p, q);
    std::cout << "The lowest common ancestor is: " << result->val << std::endl;

    // TreeNode<int>* p1 = root->left; // p = 5
    // TreeNode<int>* q1 = root->left->right->right; // q = 4
    TreeNode<int>* p1 = findNode(root, 5);  // 找到节点p1
    TreeNode<int>* q1 = findNode(root, 4);  // 找到节点q1
  
    TreeNode<int>* result1 = lowestCommonAncestor(root, p1, q1);
    std::cout << "The lowest common ancestor is: " << result1->val << std::endl;

    return 0;
}
