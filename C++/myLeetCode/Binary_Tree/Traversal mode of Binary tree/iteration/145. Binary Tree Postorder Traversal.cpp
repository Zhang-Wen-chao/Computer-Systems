// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// clang++ 145.\ Binary\ Tree\ Postorder\ Traversal.cpp -std=c++17

#include "../../../printUtils.hpp"
#include <stack>
#include <vector>

template <typename T>
std::vector<T> postOrderTraversal(TreeNode<T>* root) {
    std::vector<T> result;
    std::stack<TreeNode<T>*> stk;
    TreeNode<T>* curr = root;
    TreeNode<T>* lastVisited = nullptr;

    while (curr != nullptr || !stk.empty()) {
        // 将当前节点及其左子树的左节点依次入栈
        while (curr != nullptr) {
            stk.push(curr);
            curr = curr->left;
        }

        TreeNode<T>* top = stk.top();

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
    TreeNode<int>* root = buildTree({1, 2, 3, 4, -1, 5, 6}, -1);
    std::cout << "PostOrder traversal: ";
    printArray(postorderTraversal(root));
    deleteTree(root);
    
    return 0;
}
