// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// clang++ 105_1.cpp -std=c++17

// 已知先序与中序,建树
/*
因为前序（根左右）最先出现的总是根结点，所以令root为前序中当前的根结点下标（并且同时把一棵树分为左子树和右子树）。start为当前需要打印的子树在中序中的最左边的下标，end为当前需要打印的子树在中序中最右边的下标。递归打印这棵树的后序，递归出口为start > end。i为root所表示的值在中序中的下标，所以i即是分隔中序中对应root结点的左子树和右子树的下标。
先打印左子树，后打印右子树，最后输出当前根结点pre[root]的值。
*/

#include <algorithm>
#include "../../printUtils.hpp"

template<typename T>
void post(const std::vector<T>& pre, const std::vector<T>& in, int root, int start, int end, std::vector<T>& result) {
    if(start > end)
        return;
    
    auto i = std::find(in.begin() + start, in.begin() + end + 1, pre[root]) - in.begin();
    // echo "l" | c++filt -t
    // std::cout << "i的类型是:" << typeid(i).name() << std::endl;
    post(pre, in, root + 1, start, i - 1, result);
    post(pre, in, root + 1 + i - start, i + 1, end, result);
    
    result.push_back(pre[root]);
}

int main() {
    // 用int类型的数据测试
    std::vector<int> pre = {1, 2, 3, 4, 5, 6};
    std::vector<int> in = {3, 2, 4, 1, 6, 5};
    std::vector<int> result;
    post(pre, in, 0, 0, pre.size() - 1, result);
    printArray(result);

    // 用char类型的数据测试
    std::vector<char> pre2 = {'b', 'a', 'd', 'c', 'e'};
    std::vector<char> in2 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<char> result2;
    post(pre2, in2, 0, 0, pre2.size() - 1, result2);
    printArray(result2);

    return 0;
}