// 235. Lowest Common Ancestor of a Binary Search Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// clang++ 235.\ Lowest\ Common\ Ancestor\ of\ a\ Binary\ Search\ Tree.cpp.cpp -std=c++17
/*
这两个题目的区别是，235 题是给定一个二叉搜索树，而 236 题是给定一个普通的二叉树。二叉搜索树是一种特殊的二叉树，它满足以下性质：

对于任意一个节点，它的左子树的所有节点的值都小于它，它的右子树的所有节点的值都大于它。
它的中序遍历是一个升序序列。
因此，对于 235 题，我们可以利用二叉搜索树的性质，从根节点开始，比较它的值和 p 和 q 的值。如果它的值大于 p 和 q 的值，说明 p 和 q 都在它的左子树中，那么我们就递归地在左子树中查找 LCA。如果它的值小于 p 和 q 的值，说明 p 和 q 都在它的右子树中，那么我们就递归地在右子树中查找 LCA。如果都不满足，说明 p 和 q 分别在它的左右子树中，或者其中一个就是它本身，那么它就是 LCA。这个方法的时间复杂度是 O(H)，空间复杂度是 O(H)，其中 H 是二叉搜索树的高度1。

而对于 236 题，我们不能利用二叉搜索树的性质，因为普通的二叉树没有这样的排序规则。我们只能从根节点开始，递归地在左右子树中查找 p 和 q。如果在某个子树中找到了两个节点，那么这个子树的根节点就是 LCA。如果只在一个子树中找到了一个节点，那么这个节点就是 LCA。如果都没有找到，那么返回空指针。这个方法的时间复杂度是 O(N)，空间复杂度是 O(N)，其中 N 是二叉树的节点数2。
*/

#include "../../printUtils.hpp"

template<typename T>
TreeNode<T>* lowestCommonAncestor(TreeNode<T>* root, TreeNode<T>* p, TreeNode<T>* q) {
    if (!root) return NULL;
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}

int main() {
    TreeNode<int>* root = buildTree({6,2,8,0,4,7,9,-1,-1,3,5}, -1);
    TreeNode<int>* p = root->left; // p = 2
    TreeNode<int>* q = root->right; // q = 8

    TreeNode<int>* result = lowestCommonAncestor(root, p, q);
    std::cout << result->val << std::endl;


    TreeNode<int>* root2 = buildTree({6,2,8,0,4,7,9,-1,-1,3,5}, -1);
    TreeNode<int>* p2 = root2->left; // p = 2
    TreeNode<int>* q2 = root2->left->right; // q = 4

    TreeNode<int>* result2 = lowestCommonAncestor(root2, p2, q2);
    std::cout << result2->val << std::endl;

    return 0;
}
