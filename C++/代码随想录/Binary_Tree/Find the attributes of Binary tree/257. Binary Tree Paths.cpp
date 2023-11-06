// 257. Binary Tree Paths
// https://leetcode.com/problems/binary-tree-paths/
// clang++ 257.\ Binary\ Tree\ Paths.cpp -std=c++17
#include "../../printUtils.hpp"
#include <string>

template <typename T>
class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode<T>* root) {
        std::vector<std::string> paths;
        if (root == nullptr) {
            return paths;
        }
        std::string path;
        traverse(root, path, paths);
        return paths;
    }

private:
    void traverse(TreeNode<T>* node, std::string path, std::vector<std::string>& paths) {
        path += std::to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
        } else {
            path += "->";
            if (node->left != nullptr) {
                traverse(node->left, path, paths);
            }
            if (node->right != nullptr) {
                traverse(node->right, path, paths);
            }
        }
    }
};

int main() {
    // TreeNode<int>* root = buildTree({1, 2, 3, -1, 5}, -1);
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    printArray(Solution<int>().binaryTreePaths(root));
    deleteTree(root);
    
    return 0;
}
