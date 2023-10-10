// 968. Binary Tree Cameras
// https://leetcode.com/problems/binary-tree-cameras/

#include <iostream>
#include "../Binary_Tree/BinaryTreeUtils.hpp"

class Solution {
public:
    int minCameraCover(TreeNode<int>* root) {
        int result = 0;
        if (dfs(root, result) == 0) {
            result++;
        }
        return result;
    }

private:
    int dfs(TreeNode<int>* node, int& result) {
        if (node == nullptr) {
            return 2;
        }
        
        int left = dfs(node->left, result);
        int right = dfs(node->right, result);
        
        if (left == 0 || right == 0) {
            result++;
            return 1;
        }
        
        if (left == 1 || right == 1) {
            return 2;
        }
        
        return 0;
    }
};

int main() {
    TreeNode<int>* root = buildTree({0, 0, -1, 0, 0}, -1);
    std::cout << "Minimum number of cameras required: " << Solution().minCameraCover(root) << std::endl;
    
    TreeNode<int>* root2 = buildTree({0, 0, -1, 0, -1, 0, -1, -1, 0}, -1);
    std::cout << "Minimum number of cameras required: " << Solution().minCameraCover(root2) << std::endl;

    return 0;
}
