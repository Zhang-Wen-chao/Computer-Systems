// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 已知后序与中序，输出前序
// clang++ 106_1.cpp -std=c++17
#include <algorithm>
#include "../../printUtils.hpp"

template<typename T>
void pre(const std::vector<T>& post, const std::vector<T>& in, int root, int start, int end, std::vector<T>& result) {
    if(start > end) return ;
    auto i = std::find(in.begin() + start, in.begin() + end + 1, post[root]) - in.begin();
    // echo "l" | c++filt -t
    // std::cout << "i的类型是:" << typeid(i).name() << std::endl;
    result.push_back(post[root]);
    pre(post, in, root - 1 - end + i, start, i - 1, result);
    pre(post, in, root - 1, i + 1, end, result);
}

int main() {
    std::vector<int> post = {3, 4, 2, 6, 5, 1};
    std::vector<int> in = {3, 2, 4, 1, 6, 5};

    std::vector<int> result;
    pre(post, in, post.size() - 1, 0, post.size() - 1, result);
    std::cout << "Preorder Traversal: ";
    printArray(result);

    // 用char类型的数据测试
    std::vector<char> post2 = {'a', 'c', 'e', 'd', 'b'};
    std::vector<char> in2 = {'a', 'b', 'c', 'd', 'e'};
    std::vector<char> result2;
    pre(post2, in2, post2.size() - 1, 0, post2.size() - 1, result2);
    std::cout << "Preorder Traversal: ";
    printArray(result2);

    return 0;
}
