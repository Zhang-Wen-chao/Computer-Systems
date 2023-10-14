#ifndef PRINTUTILS_HPP
#define PRINTUTILS_HPP

#include <sstream>
#include <iostream>
#include <vector>
// 定义二叉树节点
template <typename T>
struct TreeNode {
    T val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
};
// 打印二叉树节点的存储地址
template <typename T>
void printTreeNodeAddresses(TreeNode<T>* root) {
    if (root == nullptr) return;

    std::cout << "Node: " << reinterpret_cast<uintptr_t>(root) << ", Data: " << root->val << std::endl;

    printTreeNodeAddresses(root->left);
    printTreeNodeAddresses(root->right);
}

// 打印一维数组
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const T& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// 打印二维数组
template <typename T>
void printArray(const std::vector<std::vector<T>>& arr) {
    for (const std::vector<T>& row : arr) {
        printArray(row);
    }
}

// 打印一维集合
template <typename T>
void printSet(const std::vector<T>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}
// 打印二维集合
template <typename T>
void printSet(const std::vector<std::vector<T>>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        printSet(arr[i]);
        if (i != arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Function to convert a vector to string
template<typename T>
std::string vectorToString(std::vector<T> vec) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < vec.size(); i++) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << ",";
        }
    }

    ss << "]";
    return ss.str();
}

// Function to convert a 2D vector to string
template<typename T>
std::string vectorOfVectorToString(std::vector<std::vector<T>> vec) {
    std::stringstream ss;
    ss << "[";

    for (int i = 0; i < vec.size(); i++) {
        ss << vectorToString(vec[i]);
        if (i != vec.size() - 1) {
            ss << ",";
        }
    }

    ss << "]";
    return ss.str();
}

#include <vector>
#include <queue>
#include <limits>
#include <deque>



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

template<typename T>
TreeNode<T>* findNode(TreeNode<T>* root, T value) {
    if (root == nullptr || root->val == value) {
        return root;
    }
    
    TreeNode<T>* left = findNode(root->left, value);
    TreeNode<T>* right = findNode(root->right, value);
    
    if (left != nullptr) {
        return left;
    } else {
        return right;
    }
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

// 二叉树层序遍历函数（返回一维数组）输出空节点。
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

        if (curr) {
            q.push_back(curr->left);
            q.push_back(curr->right);
        }
    }
    return result;
}

// 二叉树层序遍历函数（返回二维数组）不输出空节点。
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

// Definition for a Node in an N-ary Tree
template<typename T>
struct NTreeNode {
    T val;
    std::vector<NTreeNode*> children;
    NTreeNode(T x) : val(x) {}
};

// Utility function to build an N-ary Tree from a vector
template<typename T>
NTreeNode<T>* buildNTree(const std::vector<T>& nodes, const T& nullValue) {
    if (nodes.empty() || nodes[1] != nullValue) {
        return nullptr;
    }

    NTreeNode<T>* root = new NTreeNode<T>(nodes[0]);
    std::queue<NTreeNode<T>*> nodeQueue;
    nodeQueue.push(root);

    int i = 2; // Start from index 2 to skip the root node and the -1 marking the end of its children

    while (!nodeQueue.empty() && i < nodes.size()) {
        int levelSize = nodeQueue.size();

        for (int j = 0; j < levelSize; j++) {
            NTreeNode<T>* currNode = nodeQueue.front();
            nodeQueue.pop();

            while (i < nodes.size() && nodes[i] != nullValue) {
                NTreeNode<T>* childNode = new NTreeNode<T>(nodes[i]);
                currNode->children.push_back(childNode);
                nodeQueue.push(childNode);
                i++;
            }

            i++; // Skip the null value marking the end of children for the current node
        }
    }

    return root;
}

// Utility function to delete an N-ary Tree
template <typename T>
void deleteNTree(NTreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    for (NTreeNode<T>* child : root->children) {
        deleteNTree(child);
    }

    delete root;
}
#endif // PRINTUTILS_HPP