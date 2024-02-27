// 515. Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/
// clang++ 515.\ Find\ Largest\ Value\ in\ Each\ Tree\ Row.cpp -std=c++17

#include "../../../printUtils.hpp"
#include <limits>
#include <vector>

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
    TreeNode<int>* root = buildTree({1, 3, 2, 5, 3, -1, 9}, -1);
    std::cout << "Largest value in each tree row: ";
    printArray(largestValues(root));
    deleteTree(root);
    
    return 0;
}
