#ifndef PRINTUTILS_HPP
#define PRINTUTILS_HPP

#include <sstream>
#include <iostream>
#include <vector>

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
    std::cout << "]" << std::endl;
}

// 打印二维集合
template <typename T>
void printSet(const std::vector<std::vector<T>>& arr) {
    std::cout << "[" << std::endl;
    for (const std::vector<T>& subset : arr) {
        printSet(subset);
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

template<typename T>
void printTreePreOrder(TreeNode<T>* root) {
    if (root == nullptr) return;
    std::cout << root->val << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}
template<typename T>
void printTreeInOrder(TreeNode<T>* root) {
    if (root == nullptr) return;
    printTreeInOrder(root->left);
    std::cout << root->val << " ";
    printTreeInOrder(root->right);
}
template<typename T>
void printTreePostOrder(TreeNode<T>* root) {
    if (root == nullptr) return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    std::cout << root->val << " ";
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

#endif // PRINTUTILS_HPP