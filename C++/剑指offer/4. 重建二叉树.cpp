#include <iostream>
#include <vector>
#include <algorithm>

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(std::vector<int> pre, std::vector<int> vin) {
        if (pre.empty() || vin.empty() || pre.size() != vin.size()) {
            return nullptr;
        }
        return construct(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }

private:
    TreeNode* construct(const std::vector<int>& pre, int preStart, int preEnd,
                        const std::vector<int>& vin, int vinStart, int vinEnd) {
        // 前序遍历的第一个数字是根节点的值
        int rootValue = pre[preStart];
        TreeNode* root = new TreeNode(rootValue);

        // 在中序遍历中找到根节点的位置
        int rootInVin = vinStart;
        while (vin[rootInVin] != rootValue && rootInVin <= vinEnd) {
            ++rootInVin;
        }

        // 计算左子树的长度
        int leftLength = rootInVin - vinStart;
        // 计算左子树的前序遍历的结束位置
        int leftPreEnd = preStart + leftLength;

        // 递归构造左子树
        if (leftLength > 0) {
            root->left = construct(pre, preStart + 1, leftPreEnd, vin, vinStart, rootInVin - 1);
        }
        // 递归构造右子树
        if (leftLength < preEnd - preStart) {
            root->right = construct(pre, leftPreEnd + 1, preEnd, vin, rootInVin + 1, vinEnd);
        }

        return root;
    }
};

// 前序遍历打印二叉树
void preOrderPrint(TreeNode* node) {
    if (node != nullptr) {
        std::cout << node->val << " ";
        preOrderPrint(node->left);
        preOrderPrint(node->right);
    }
}

// 清理二叉树内存
void deleteTree(TreeNode* node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    std::vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    std::vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};

    Solution solution;
    TreeNode* root = solution.reConstructBinaryTree(pre, vin);

    std::cout << "PreOrder: ";
    preOrderPrint(root);
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}
