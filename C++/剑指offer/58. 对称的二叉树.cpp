#include <iostream>

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
    bool isSymmetric(TreeNode* root) {
        return root == nullptr || isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) {
            return left == right;
        }
        if (left->val != right->val) {
            return false;
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

int main() {
    // Construct a symmetric binary tree as an example
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(4);
    TreeNode g(3);

    a.left = &b;
    a.right = &c;

    b.left = &d;
    b.right = &e;

    c.left = &f;
    c.right = &g;

    Solution solution;
    bool result = solution.isSymmetric(&a);

    cout << "The tree is " << (result ? "symmetric." : "not symmetric.") << endl;

    return 0;
}
