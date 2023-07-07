// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include "../../BinaryTreeUtils.hpp"

template <typename T>
struct NTreeNode {
    T val;
    std::vector<NTreeNode*> children;

    NTreeNode(T x) : val(x) {}
};

// N叉树层序遍历函数
template <typename T>
std::vector<std::vector<T>> levelOrder(NTreeNode<T>* root) {
    std::vector<std::vector<T>> result;
    if (root == nullptr) return result;

    std::queue<NTreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<T> level;

        for (int i = 0; i < size; i++) {
            NTreeNode<T>* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            for (NTreeNode<T>* child : curr->children) {
                q.push(child);
            }
        }
        result.push_back(level);
    }

    return result;
}

int main() {
    // 构建测试N叉树
    NTreeNode<int>* root = new NTreeNode<int>(1);
    NTreeNode<int>* node2 = new NTreeNode<int>(2);
    NTreeNode<int>* node3 = new NTreeNode<int>(3);
    NTreeNode<int>* node4 = new NTreeNode<int>(4);
    NTreeNode<int>* node5 = new NTreeNode<int>(5);
    NTreeNode<int>* node6 = new NTreeNode<int>(6);

    root->children.push_back(node3);
    root->children.push_back(node2);
    root->children.push_back(node4);

    node3->children.push_back(node5);
    node3->children.push_back(node6);

    std::vector<std::vector<int>> result = levelOrder(root);
    std::cout << "Level Order Traversal of N-ary Tree:" << std::endl;
    printArray(result);

    return 0;
}
