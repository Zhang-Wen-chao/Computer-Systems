#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stack;
        while (true) {
            while (root != nullptr) {
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            if (--k == 0) return root;
            root = root->right;
        }
    }
};

// Helper function to insert nodes into the BST
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;
    // Insert elements into the BST
    vector<int> elements = {5, 3, 6, 2, 4, 1};
    for (int val : elements) {
        root = insertIntoBST(root, val);
    }

    Solution solution;
    int k = 3; // Change this value to find the k-th smallest element
    TreeNode* kthNode = solution.kthSmallest(root, k);
    cout << "The " << k << "th smallest element in the BST is: " << kthNode->val << endl;

    // Clean up memory if needed
    // ...

    return 0;
}
