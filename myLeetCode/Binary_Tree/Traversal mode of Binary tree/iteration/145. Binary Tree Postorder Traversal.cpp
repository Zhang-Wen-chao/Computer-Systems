// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

#include "../../BinaryTreeUtils.hpp"
#include <stack>

std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stk;
    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while (curr != nullptr || !stk.empty()) {
        // 将当前节点及其左子树的左节点依次入栈
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }

        TreeNode* top = stk.top();

        // 检查右子树是否已经访问过，或者右子树为空
        if (top->right == nullptr || top->right == lastVisited) {
            stk.pop();
            result.push_back(top->val);
            lastVisited = top;
        } else {
            // 处理右子树
            curr = top->right;
        }
    }

    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 2, 3, 4, INT_MAX, 5, 6};
    TreeNode* root = buildTree(levelOrderValues);
    std::vector<int> result = postorderTraversal(root);

    std::cout << "Postorder traversal: ";
    print_1d(result);

    return 0;
}
