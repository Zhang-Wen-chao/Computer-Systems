// 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
// clang++ 450.\ Delete\ Node\ in\ a\ BST.cpp -std=c++17
#include "../../printUtils.hpp"

template<typename T>
class Solution {
public:
    // Find the minimum value in the right subtree
    int findMin(TreeNode<T>* root) {
        while (root->left) {
            root = root->left;
        }
        return root->val;
    }
    // Delete a node from a BST and return the new root
    TreeNode<T>* deleteNode(TreeNode<T>* root, int key) {
        if (!root) return nullptr;
        
        // If the key is smaller than the root, delete from the left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // If the key is larger than the root, delete from the right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // If the key is equal to the root, delete the root
        else {
            // Case 1: no child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // Case 2: one child
            else if (!root->left || !root->right) {
                TreeNode<T>* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            // Case 3: two children
            else {
                int successor = findMin(root->right);
                root->val = successor;
                root->right = deleteNode(root->right, successor);
            }
        }
        return root;
    }
};

int main() {
    TreeNode<int>* root = buildTree({5, 3, 6, 2, 4, -1, 7}, -1);
    int key = 3;
    TreeNode<int>* result = Solution<int>().deleteNode(root, key);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result));

    TreeNode<int>* root2 = buildTree({5, 3, 6, 2, 4, -1, 7}, -1);
    int key2 = 0;
    TreeNode<int>* result2 = Solution<int>().deleteNode(root2, key2);
    std::cout << "The result is: " << std::endl;
    printArray(levelOrder(result2));

    return 0;
}

