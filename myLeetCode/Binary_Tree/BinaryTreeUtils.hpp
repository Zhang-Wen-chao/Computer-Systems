#ifndef BINARYTREEUTILS_HPP
#define BINARYTREEUTILS_HPP

#include <iostream>
#include <vector>
#include <queue>

// 定义二叉树节点
template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};

// 重载的 buildTree 函数（根据层序遍历结果构建二叉树）
template <typename T>
TreeNode<T>* buildTree(const std::vector<T>& levelOrderValues, const T& nullValue) {
    if (levelOrderValues.empty()) {
        return nullptr;
    }

    TreeNode<T>* root = new TreeNode<T>(levelOrderValues[0]);
    std::queue<TreeNode<T>*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < levelOrderValues.size()) {
        TreeNode<T>* curr = q.front();
        q.pop();

        if (levelOrderValues[i] != nullValue) {
            curr->left = new TreeNode<T>(levelOrderValues[i]);
            q.push(curr->left);
        }
        i++;

        if (i < levelOrderValues.size() && levelOrderValues[i] != nullValue) {
            curr->right = new TreeNode<T>(levelOrderValues[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// 二叉树层序遍历函数（返回一维数组）
template <typename T>
std::vector<T> levelOrder(TreeNode<T>* root) {
    std::vector<T> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<T>* curr = q.front();
        q.pop();

        result.push_back(curr->val);

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return result;
}

// 二叉树层序遍历函数（返回二维数组）
template <typename T>
std::vector<std::vector<T>> levelOrder2D(TreeNode<T>* root) {
    std::vector<std::vector<T>> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        std::vector<T> level;

        for (int i = 0; i < size; i++) {
            TreeNode<T>* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(level);
    }

    return result;
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printArray(const std::vector<std::vector<T>>& arr) {
    for (const std::vector<T>& row : arr) {
        printArray(row);
    }
}

#endif // BINARYTREEUTILS_HPP