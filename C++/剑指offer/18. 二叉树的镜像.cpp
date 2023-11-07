#include <iostream>
#include <algorithm> // 用于std::swap

// 定义二叉树的结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
void Mirror(TreeNode *root);

int main() {
    // 构建一棵树
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);

    // 转换成镜像
    Mirror(root);

    // 输出镜像后的树的根节点值，以及左右子节点值作为验证
    std::cout << "Root: " << root->val << std::endl;
    if (root->left) std::cout << "Left child of root: " << root->left->val << std::endl;
    if (root->right) std::cout << "Right child of root: " << root->right->val << std::endl;

    // 清理内存
    // 注意：这里没有实现完整的树的析构，这只是为了示例。
    // 在实际应用中，你需要确保正确地删除所有节点以避免内存泄漏。
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// 函数定义
void Mirror(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    std::swap(root->left, root->right); // 交换左右子树

    // 递归对左右子树进行镜像操作
    if (root->left) {
        Mirror(root->left);
    }
    if (root->right) {
        Mirror(root->right);
    }
}
