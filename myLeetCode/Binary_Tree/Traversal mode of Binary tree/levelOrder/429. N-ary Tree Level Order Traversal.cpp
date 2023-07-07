// 429. N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include "../../BinaryTreeUtils.hpp"

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
    NTreeNode<int>* root = buildNTree({1, -1, 3, 2, 4, -1, 5, 6}, -1);
    std::cout << "Level Order Traversal of N-ary Tree:" << std::endl;
    printArray(levelOrder(root));

    return 0;
}
