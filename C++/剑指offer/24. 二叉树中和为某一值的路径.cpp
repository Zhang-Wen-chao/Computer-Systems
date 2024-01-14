#include <iostream>
#include <vector>

using namespace std;

// 定义二叉树的结构
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths);
vector<vector<int>> pathSum(TreeNode* root, int sum);

int main() {
    // 构建一棵树
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    // 寻找和为22的路径
    int sum = 22;
    vector<vector<int>> result = pathSum(root, sum);
    for (const auto& path : result) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }

    // 清理内存
    // 注意：这里没有实现完整的树的析构，这只是为了示例。
    // 在实际应用中，你需要确保正确地删除所有节点以避免内存泄漏。
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// 函数定义
void findPaths(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right && root->val == sum) {
        paths.push_back(path);
    } else {
        findPaths(root->left, sum - root->val, path, paths);
        findPaths(root->right, sum - root->val, path, paths);
    }
    path.pop_back(); // 返回上一节点前在路径上删除当前节点
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> paths;
    vector<int> path;
    findPaths(root, sum, path, paths);
    return paths;
}
