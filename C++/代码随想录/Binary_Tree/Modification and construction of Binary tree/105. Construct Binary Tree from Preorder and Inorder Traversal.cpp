// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// clang++ 105.\ Construct\ Binary\ Tree\ from\ Preorder\ and\ Inorder\ Traversal.cpp -std=c++17

// 已知先序与中序,输出后序
/*
因为前序（根左右）最先出现的总是根结点，所以令root为前序中当前的根结点下标（并且同时把一棵树分为左子树和右子树）。start为当前需要打印的子树在中序中的最左边的下标，end为当前需要打印的子树在中序中最右边的下标。递归打印这棵树的后序，递归出口为start > end。i为root所表示的值在中序中的下标，所以i即是分隔中序中对应root结点的左子树和右子树的下标。
先打印左子树，后打印右子树，最后输出当前根结点pre[root]的值。
*/

#include <algorithm>
#include "../../printUtils.hpp"

template <typename T>
TreeNode<T>* buildTree(const std::vector<T>& pre, const std::vector<T>& in, int root, int start, int end) {
    if(start > end) 
        return nullptr;

    auto i = std::find(in.begin() + start, in.begin() + end + 1, pre[root]) - in.begin();
    // 这样就可以在in的[start, end]区间内查找post[root]的位置，并且返回它的下标。注意，find函数的第二个参数是要查找的区间的结束位置的下一个迭代器，所以要加上1。另外，find函数返回的是一个迭代器，所以要减去in.begin()来得到下标。
    TreeNode<T>* t = new TreeNode<T>(pre[root]);
    t->left = buildTree(pre, in, root + 1, start, i - 1);
    t->right = buildTree(pre, in, root + 1 + i - start, i + 1, end);

    return t;
}

int main(){
    std::vector<int> pre = {3, 9, 20, 15, 7};
    std::vector<int> in = {9, 3, 15, 20, 7};
    TreeNode<int>* root = buildTree(pre, in, 0, 0, pre.size() - 1);
    std::cout << "levelOrder Traversal: ";
    printArray(levelOrder(root));
    deleteTree(root);
    

    // 用char类型的数据测试
    std::vector<char> pre2 = {'b', 'a', 'd', 'c', 'e'};
    std::vector<char> in2 = {'a', 'b', 'c', 'd', 'e'};
    TreeNode<char>* root2 = buildTree(pre2, in2, 0, 0, pre2.size() - 1);
    std::cout << "levelOrder Traversal: ";
    printArray(levelOrder(root2));
    deleteTree(root2);

    return 0;
}


