// 637. Average of Levels in Binary Tree
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

// clang++ 637.\ Average\ of\ Levels\ in\ Binary\ Tree.cpp -std=c++17

#include "../../../printUtils.hpp"

std::vector<double> averageOfLevels(TreeNode<int>* root) {
    std::vector<double> result;
    if (root == nullptr) return result;

    std::queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double sum = 0.0;
        for (int i = 0; i < size; i++) {
            TreeNode<int>* curr = q.front();
            q.pop();

            sum += curr->val;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        result.push_back(sum / size);
    }
    return result;
}

int main() {
    TreeNode<int>* root = buildTree({3, 9, 20, -1, -1, 15, 7}, -1);
    std::cout << "Average of Levels in Binary Tree:" << std::endl;
    printArray(averageOfLevels(root));
    deleteTree(root);
    
    return 0;
}