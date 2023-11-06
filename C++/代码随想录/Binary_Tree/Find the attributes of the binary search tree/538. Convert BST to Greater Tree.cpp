// 538. Convert BST to Greater Tree
// https://leetcode.com/problems/convert-bst-to-greater-tree/
// clang++ 538.\ Convert\ BST\ to\ Greater\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    TreeNode<T>* convertBST(TreeNode<T>* root) {
        T sum = 0;
        convertBST(root, sum);
        return root;
    }
    
    void convertBST(TreeNode<T>* root, T& sum) {
        if (!root) return;

        convertBST(root->right, sum);
        root->val += sum;
        sum += root->val - sum;
        convertBST(root->left, sum);
    }
};

int main() {
    TreeNode<int>* root = buildTree({4, 1, 6, 0, 2, 5, 7, -1, -1, -1, 3, -1, -1, -1, 8}, -1);
    TreeNode<int>* result = Solution<int>().convertBST(root);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result));

    TreeNode<int>* root2 = buildTree({0, -1, 1}, -1);
    TreeNode<int>* result2 = Solution<int>().convertBST(root2);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result2));

    TreeNode<double>* root3 = buildTree({1.87, 0.24, 2.98}, -1.0);
    TreeNode<double>* result3 = Solution<double>().convertBST(root3);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result3));

    return 0;

}
