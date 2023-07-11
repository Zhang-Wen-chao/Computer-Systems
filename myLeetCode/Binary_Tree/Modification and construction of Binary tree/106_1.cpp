// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 已知后序与中序，输出前序

#include "../printUtils.hpp"

template<typename T>
void pre(const std::vector<T>& post, const std::vector<T>& in, int root, int start, int end, std::vector<T>& result) {
    if(start > end) return ;
    int i = start;
    while(i < end && in[i] != post[root]) i++;

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
    
    return 0;
}
