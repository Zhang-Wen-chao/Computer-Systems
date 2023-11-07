#include <iostream>
#include <deque>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        deque<TreeNode*> nodeQueue;
        nodeQueue.push_back(root);
        bool leftToRight = true;

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node;
                if (leftToRight) {
                    node = nodeQueue.front();
                    nodeQueue.pop_front();
                    if (node->left) nodeQueue.push_back(node->left);
                    if (node->right) nodeQueue.push_back(node->right);
                } else {
                    node = nodeQueue.back();
                    nodeQueue.pop_back();
                    if (node->right) nodeQueue.push_front(node->right);
                    if (node->left) nodeQueue.push_front(node->left);
                }
                currentLevel.push_back(node->val);
            }
            result.push_back(currentLevel);
            leftToRight = !leftToRight; // Toggle the direction
        }

        return result;
    }
};

void printZigzag(const vector<vector<int>>& zigzag) {
    for (const auto& level : zigzag) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage:
    // Construct a binary tree:
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> zigzag = solution.zigzagLevelOrder(root);
    cout << "Zigzag Level Order:" << endl;
    printZigzag(zigzag);

    // Clean up memory if needed
    // ...

    return 0;
}
