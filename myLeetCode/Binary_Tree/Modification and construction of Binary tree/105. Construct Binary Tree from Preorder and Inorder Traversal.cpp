// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// 已知先序与中序,输出后序
/*
因为前序（根左右）最先出现的总是根结点，所以令root为前序中当前的根结点下标（并且同时把一棵树分为左子树和右子树）。start为当前需要打印的子树在中序中的最左边的下标，end为当前需要打印的子树在中序中最右边的下标。递归打印这棵树的后序，递归出口为start > end。i为root所表示的值在中序中的下标，所以i即是分隔中序中对应root结点的左子树和右子树的下标。
先打印左子树，后打印右子树，最后输出当前根结点pre[root]的值。
*/

#include "../BinaryTreeUtils.hpp"
#include "../printUtils.hpp"
#include <algorithm>

TreeNode<int>* buildTree(const std::vector<int>& pre, const std::vector<int>& in, int root, int start, int end) {
    if(start > end) 
        return nullptr;

    int i = std::find(in.begin() + start, in.begin() + end + 1, pre[root]) - in.begin();

    TreeNode<int>* t = new TreeNode<int>(pre[root]);
    t->left = buildTree(pre, in, root + 1, start, i - 1);
    t->right = buildTree(pre, in, root + 1 + i - start, i + 1, end);
    return t;
}

int main(){
    // std::vector<int> pre = {1, 2, 3, 4, 5, 6};
    // std::vector<int> in = {3, 2, 4, 1, 6, 5};



    TreeNode<int>* root = buildTree(pre, in, 0, 0, pre.size() - 1);
    std::cout << "Postorder Traversal: ";
    printArray(postorderTraversal(root));

    std::cout << "levelOrder Traversal: ";
    printArray(levelOrder(root));

    deleteTree(root);
    
    return 0;
}


