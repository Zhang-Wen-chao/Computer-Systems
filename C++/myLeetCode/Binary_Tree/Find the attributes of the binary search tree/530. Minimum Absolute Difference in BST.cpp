// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// clang++ 530.\ Minimum\ Absolute\ Difference\ in\ BST.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    int getMinimumDifference(TreeNode<T>* root) {
        int minimumDiff = std::numeric_limits<T>::max();
        int prevVal = -1;
        inorderTraversal(root, prevVal, minimumDiff);
        return minimumDiff;
    }
    
private:
    void inorderTraversal(TreeNode<T>* node, int& prevVal, int& minimumDiff) {
        if (node == nullptr) {
            return;
        }
        
        inorderTraversal(node->left, prevVal, minimumDiff);
        
        if (prevVal != -1) {
            minimumDiff = std::min(minimumDiff, std::abs(prevVal - node->val));
        }
        prevVal = node->val;
        
        inorderTraversal(node->right, prevVal, minimumDiff);
    }
};

int main() {
    // TreeNode<int>* root = buildTree({4, 2, 6, 1, 3}, -1);
    // TreeNode<int>* root = buildTree({1, 0, 48, -1, -1, 12, 49}, -1);
    TreeNode<int>* root = buildTree({1, -76, 48, -1, -1, 12, 99}, -1);
    printArray(levelOrder(root));
    std::cout << "Minimum absolute difference in BST: " << Solution<int>().getMinimumDifference(root) << std::endl;
    deleteTree(root);
    
    return 0;
}
