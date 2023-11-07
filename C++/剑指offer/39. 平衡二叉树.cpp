#include <iostream>
#include <algorithm>

using namespace std;

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
bool IsBalanced(TreeNode* root);
int CheckDepth(TreeNode* root, bool& balanced);

int main() {
    // 示例代码，创建一个二叉树
    //      1
    //     / \
    //    2   3
    //   / 
    //  4   
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    bool isBalanced = IsBalanced(root);
    cout << "The tree is " << (isBalanced ? "" : "not ") << "balanced." << endl;

    // 清理内存，防止内存泄漏
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// 函数定义
bool IsBalanced(TreeNode* root) {
    bool balanced = true;
    CheckDepth(root, balanced);
    return balanced;
}

int CheckDepth(TreeNode* root, bool& balanced) {
    if (root == nullptr) return 0;
    int leftDepth = CheckDepth(root->left, balanced);
    int rightDepth = CheckDepth(root->right, balanced);

    if (abs(leftDepth - rightDepth) > 1) {
        balanced = false;
    }
    return max(leftDepth, rightDepth) + 1;
}
