#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义二叉树的结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
vector<int> PrintFromTopToBottom(TreeNode* root);

int main() {
    // 构建一棵树
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(11);

    // 从上往下打印二叉树
    vector<int> result = PrintFromTopToBottom(root);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

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
vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    return result;
}
