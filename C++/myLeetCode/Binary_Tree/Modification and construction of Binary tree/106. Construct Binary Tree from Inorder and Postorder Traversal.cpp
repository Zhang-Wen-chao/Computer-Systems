// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 已知后序与中序,建树
// clang++ 106.\ Construct\ Binary\ Tree\ from\ Inorder\ and\ Postorder\ Traversal.cpp -std=c++17

#include "../../printUtils.hpp"
#include <algorithm>

template<typename T>
TreeNode<T>* buildTree(const std::vector<T>& post, const std::vector<T>& in, int root, int start, int end) {
    if(start > end) return nullptr;
    int i = std::find(in.begin() + start, in.begin() + end + 1, post[root]) - in.begin();
    // 这样就可以在in的[start, end]区间内查找post[root]的位置，并且返回它的下标。注意，find函数的第二个参数是要查找的区间的结束位置的下一个迭代器，所以要加上1。另外，find函数返回的是一个迭代器，所以要减去in.begin()来得到下标。

    TreeNode<T>* t = new TreeNode<T>(post[root]);
    t->left = buildTree(post, in, root - 1 - end + i, start, i - 1);
    t->right = buildTree(post, in, root - 1, i + 1, end);

    return t;
}

int main() {
    std::vector<int> post = {9, 15, 7, 20, 3};
    std::vector<int> in = {9, 3, 15, 20, 7};
    TreeNode<int>* root = buildTree(post, in, post.size() - 1, 0, post.size() - 1);

    std::cout << "levelOrder Traversal: ";
    printArray(levelOrder(root));
    deleteTree(root);

    // 用char类型的数据测试
    std::vector<char> post2 = {'a', 'c', 'e', 'd', 'b'};
    std::vector<char> in2 = {'a', 'b', 'c', 'd', 'e'};
    TreeNode<char>* root2 = buildTree(post2, in2, post2.size() - 1, 0, post2.size() - 1);
    std::cout << "levelOrder Traversal: ";
    printArray(levelOrder(root2));
    deleteTree(root2);

    return 0;
}
