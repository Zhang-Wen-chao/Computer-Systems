#include <iostream>

using namespace std;

// 定义二叉树的结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
void ConvertNode(TreeNode* node, TreeNode** lastNodeInList);
TreeNode* Convert(TreeNode* root);

int main() {
    // 构建二叉搜索树
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(14);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(16);

    // 将二叉搜索树转换成双向链表
    TreeNode* head = Convert(root);

    // 打印转换后的双向链表
    TreeNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->right;
    }
    cout << endl;

    // 清理内存，注意：这里没有删除转换后的双向链表中的所有节点，这只是为了示例。
    // 在实际应用中，你需要确保正确地删除所有节点以避免内存泄漏。
    // ...

    return 0;
}

// 函数定义
void ConvertNode(TreeNode* node, TreeNode** lastNodeInList) {
    if (node == nullptr) return;

    TreeNode* current = node;

    // 转换左子树
    if (current->left != nullptr) {
        ConvertNode(current->left, lastNodeInList);
    }

    // 链接当前节点
    current->left = *lastNodeInList;
    if (*lastNodeInList != nullptr) {
        (*lastNodeInList)->right = current;
    }

    *lastNodeInList = current;

    // 转换右子树
    if (current->right != nullptr) {
        ConvertNode(current->right, lastNodeInList);
    }
}

TreeNode* Convert(TreeNode* root) {
    TreeNode* lastNodeInList = nullptr;
    ConvertNode(root, &lastNodeInList);

    // 找到双向链表的头节点
    TreeNode* head = lastNodeInList;
    while (head != nullptr && head->left != nullptr) {
        head = head->left;
    }
    return head;
}
