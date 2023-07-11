#ifndef BINARYTREEUTILS_HPP
#define BINARYTREEUTILS_HPP

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

template <typename T>
void deleteTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

template <typename T>
void preorderTraversal(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    result.push_back(root->val); // 将当前节点的值加入结果数组
    preorderTraversal(root->left, result); // 递归遍历左子树
    preorderTraversal(root->right, result); // 递归遍历右子树
}

template <typename T>
std::vector<T> preorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    preorderTraversal(root, result);
    return result;
}


template <typename T>
void inorderTraversal(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result); // 递归遍历左子树
    result.push_back(root->val); // 将当前节点的值加入结果数组
    inorderTraversal(root->right, result); // 递归遍历右子树
}

template <typename T>
std::vector<T> inorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    inorderTraversal(root, result);
    return result;
}

template <typename T>
void postorderTraversal(TreeNode<T>* root, std::vector<T>& result) {
    if (root == nullptr) return;
    postorderTraversal(root->left, result); // 递归遍历左子树
    postorderTraversal(root->right, result); // 递归遍历右子树
    result.push_back(root->val); // 将当前节点的值加入结果数组
}

template <typename T>
std::vector<T> postorderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    postorderTraversal(root, result);
    return result;
}

// 二叉树层序遍历函数（返回一维数组）
/*

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
*/






/*
#include <limits> // 需要包含这个头文件
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

        // 判断curr是否为空，如果为空，就用一个特殊值代替
        if (curr == nullptr) {
            // 如果是char类型，就用'#'作为特殊值
            if constexpr (std::is_same_v<T, char>) {
                result.push_back('#');
            }
            // 否则就用当前类型的最小值或最大值作为特殊值
            else {
                result.push_back(std::numeric_limits<T>::lowest());
                // 或者 result.push_back(std::numeric_limits<T>::max());
            }
        }
        else {
            result.push_back(curr->val);
        }

        if (curr) { // 如果curr不为空，才把它的左右孩子入队
            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return result;
}
*/
#include <limits> // 需要包含这个头文件
#include <deque> // 需要包含这个头文件
// 二叉树层序遍历函数（返回一维数组）
template <typename T>
std::vector<T> levelOrder(TreeNode<T>* root) {
    std::vector<T> result;
    if (root == nullptr) return result;

    std::deque<TreeNode<T>*> q; // 用std::deque代替std::queue
    q.push_back(root);

    while (!q.empty()) {
        // 判断队列里是否只剩下空节点，如果是，就跳出循环
        bool allNull = true;
        for (auto node : q) { // 用q.begin()和q.end()来遍历底层容器
            if (node != nullptr) {
                allNull = false;
                break;
            }
        }
        if (allNull) break;

        TreeNode<T>* curr = q.front();
        q.pop_front();

        // 判断curr是否为空，如果为空，就用一个特殊值代替
        if (curr == nullptr) {
            // 如果是char类型，就用'#'作为特殊值
            if constexpr (std::is_same_v<T, char>) {
                result.push_back('#');
            }
            // 否则就用当前类型的最小值或最大值作为特殊值
            else {
                result.push_back(std::numeric_limits<T>::lowest());
                // 或者 result.push_back(std::numeric_limits<T>::max());
            }
        }
        else {
            result.push_back(curr->val);
        }

        if (curr) { // 如果curr不为空，才把它的左右孩子入队
            q.push_back(curr->left);
            q.push_back(curr->right);
        }
    }

    return result;
}


// 二叉树层序遍历函数（返回二维数组）
template <typename T>
std::vector<std::vector<T>> levelOrder(TreeNode<T>* root, int dummyParam) {
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

#endif // BINARYTREEUTILS_HPP