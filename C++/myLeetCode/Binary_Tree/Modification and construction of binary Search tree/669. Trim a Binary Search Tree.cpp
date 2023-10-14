// 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/
// clang++ 669.\ Trim\ a\ Binary\ Search\ Tree.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    // Trim a BST to only contain values in the range [low, high]
    TreeNode<T>* trimBST(TreeNode<T>* root, int low, int high) {
        // Base case: empty tree
        if (!root) return nullptr;
        
        // If the root value is smaller than the low bound, trim the left subtree and return the right subtree
        if (root->val < low) {
            TreeNode<T>* right = trimBST(root->right, low, high);
            delete root;
            return right;
        }
        // If the root value is larger than the high bound, trim the right subtree and return the left subtree
        else if (root->val > high) {
            TreeNode<T>* left = trimBST(root->left, low, high);
            delete root;
            return left;
        }
        // If the root value is in the range, trim both subtrees and return the root
        else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
    }
};

int main() {
    TreeNode<int>* root = buildTree({1, 0, 2}, -1);
    int low = 1, high = 2;
    TreeNode<int>* result = Solution<int>().trimBST(root, low, high);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result));

    TreeNode<int>* root2 = buildTree({3, 0, 4, -1, 2, -1, -1, 1}, -1);
    int low2 = 1, high2 = 3;
    TreeNode<int>* result2 = Solution<int>().trimBST(root2, low2, high2);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result2));

    return 0;
}
