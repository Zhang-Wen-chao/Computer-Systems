#include <iostream>

// 定义二叉树的结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2);

int main() {
    // 构建两棵树，Tree1 和 Tree2
    TreeNode* Tree1 = new TreeNode(8);
    Tree1->left = new TreeNode(8);
    Tree1->right = new TreeNode(7);
    Tree1->left->left = new TreeNode(9);
    Tree1->left->right = new TreeNode(2);
    Tree1->left->right->left = new TreeNode(4);
    Tree1->left->right->right = new TreeNode(7);

    TreeNode* Tree2 = new TreeNode(8);
    Tree2->left = new TreeNode(9);
    Tree2->right = new TreeNode(2);

    // 判断Tree2是否是Tree1的子结构
    bool result = HasSubtree(Tree1, Tree2);
    std::cout << "Tree2 is a subtree of Tree1: " << (result ? "Yes" : "No") << std::endl;

    // 清理内存
    // 注意：这里没有实现完整的树的析构，这只是为了示例。
    // 在实际应用中，你需要确保正确地删除所有节点以避免内存泄漏。
    delete Tree1->left->right->right;
    delete Tree1->left->right->left;
    delete Tree1->left->right;
    delete Tree1->left->left;
    delete Tree1->left;
    delete Tree1->right;
    delete Tree1;

    delete Tree2->right;
    delete Tree2->left;
    delete Tree2;

    return 0;
}

// 函数定义
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    bool result = false;
    if (pRoot1 != nullptr && pRoot2 != nullptr) {
        if (pRoot1->val == pRoot2->val) {
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->left, pRoot2);
        }
        if (!result) {
            result = HasSubtree(pRoot1->right, pRoot2);
        }
    }
    return result;
}

bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == nullptr) {
        return true;
    }
    if (pRoot1 == nullptr) {
        return false;
    }
    if (pRoot1->val != pRoot2->val) {
        return false;
    }
    return DoesTree1HaveTree2(pRoot1->left, pRoot2->left) && DoesTree1HaveTree2(pRoot1->right, pRoot2->right);
}
