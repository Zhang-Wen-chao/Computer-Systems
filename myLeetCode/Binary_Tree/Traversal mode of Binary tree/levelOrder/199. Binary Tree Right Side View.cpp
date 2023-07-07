// 199. Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view/

#include "../../BinaryTreeUtils.hpp"
#include <queue>

// 二叉树右视图函数
std::vector<int> rightSideView(TreeNode<int>* root) {
    std::vector<int> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode<int>* curr = q.front();
            q.pop();

            // 将每层最右边的节点值加入结果向量
            if (i == size - 1) {
                result.push_back(curr->val);
            }

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
            }
        }
    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, -1, 5, -1, 4};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<int> result = rightSideView(root);

    std::cout << "Right Side View of Binary Tree:" << std::endl;
    printArray(result);

    return 0;
}
