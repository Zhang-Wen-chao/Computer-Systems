#ifndef BINARYTREEUTILS_HPP
#define BINARYTREEUTILS_HPP

#include <vector>
#include <queue>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const std::vector<int>& levelOrderValues) {
    if (levelOrderValues.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(levelOrderValues[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrderValues.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (levelOrderValues[i] != INT_MAX) {
            curr->left = new TreeNode(levelOrderValues[i]);
            q.push(curr->left);
        }
        i++;

        if (i < levelOrderValues.size() && levelOrderValues[i] != INT_MAX) {
            curr->right = new TreeNode(levelOrderValues[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

#endif // BINARYTREEUTILS_HPP