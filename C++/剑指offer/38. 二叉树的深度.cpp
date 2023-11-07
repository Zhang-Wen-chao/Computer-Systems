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
int TreeDepth(TreeNode* pRoot);

int main() {
    // 示例代码，创建一个二叉树
    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    //     /
    //    7
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);

    int depth = TreeDepth(root);
    cout << "The depth of the tree is: " << depth << endl;

    // 清理内存，防止内存泄漏
    // 注意：这里仅删除了示例中创建的节点，实际使用时应根据实际情况来删除
    delete root->left->right->left;
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// 函数定义
int TreeDepth(TreeNode* pRoot) {
    if (pRoot == nullptr) {
        return 0;
    }
    int leftDepth = TreeDepth(pRoot->left);
    int rightDepth = TreeDepth(pRoot->right);
    return max(leftDepth, rightDepth) + 1;
}
