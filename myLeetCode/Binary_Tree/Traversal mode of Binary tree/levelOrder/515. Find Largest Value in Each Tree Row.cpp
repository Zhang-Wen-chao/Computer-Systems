// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

#include "../../BinaryTreeUtils.hpp"
#include <limits>

// 找出每一行中的最大值
template <typename T>
std::vector<T> largestValues(TreeNode<T>* root) {
    std::vector<T> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        T maxVal = std::numeric_limits<T>::lowest(); 

        for (int i = 0; i < size; i++) {
            TreeNode<T>* curr = q.front();
            q.pop();

            maxVal = std::max(maxVal, curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(maxVal);
    }

    return result;
}

int main() {
    std::vector<int> levelOrderValues = {1, 3, 2, 5, 3, -1, 9};
    TreeNode<int>* root = buildTree(levelOrderValues, -1);

    std::vector<int> result = largestValues(root);

    std::cout << "Largest value in each tree row: ";
    printArray(result);
    std::cout << std::endl;

    return 0;
}
