// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// clang++ 98.\ Validate\ Binary\ Search\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    bool isValidBST(TreeNode<T>* root) {
        if (!root) return true;
        T minVal = std::numeric_limits<T>::lowest();
        T maxVal = std::numeric_limits<T>::max();
        return isValidBST(root, minVal, maxVal);
    }

private:
    bool isValidBST(TreeNode<T>* root, T minVal, T maxVal) {
        if (!root) return true;
        
        if (root->val <= minVal || root->val >= maxVal) return false;

        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
};

int main() {
    TreeNode<int>* root = buildTree({5, 1, 4, -1, -1, 3, 6}, -1);
    printArray(levelOrder(root));
    std::cout << std::boolalpha << Solution<int>().isValidBST(root) << std::endl;

    std::cout << "====================" << std::endl;
    
    TreeNode<int>* root1 = buildTree({2, 1, 3}, -1);
    printArray(levelOrder(root1));
    std::cout << std::boolalpha << Solution<int>().isValidBST(root1) << std::endl;

    return 0;
}
