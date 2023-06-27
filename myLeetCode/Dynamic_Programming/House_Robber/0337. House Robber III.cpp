// 337. House Robber III
// https://leetcode.com/problems/house-robber-iii/

// 这个代码的意思是，用一个类Solution封装了一个函数rob，它接受一个二
// 叉树的根节点作为参数，返回小偷能偷到的最大金额。它调用了一个辅助函数
// robTree，它也接受一个二叉树的节点作为参数，返回一个长度为2的数组，表示不
// 偷和偷当前节点能得到的最大金额。它用了和我之前给你的代码相同的逻辑，只是
// 写法不同。


// 包含必要的头文件
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 定义解决方案类
class Solution {
public:
    int rob(TreeNode* root) {
        // 调用辅助函数得到一个长度为2的数组
        vector<int> result = robTree(root);
        // 返回数组中的最大值
        return max(result[0], result[1]);
    }
    // 长度为2的数组，0：不偷，1：偷
    vector<int> robTree(TreeNode* cur) {
        // 如果当前节点为空，返回两个0
        if (cur == NULL) return vector<int>{0, 0};
        // 递归计算左右子树的结果
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        // 如果偷当前节点，那么不能偷左右子节点，只能加上它们不偷时的最大值
        int val1 = cur->val + left[0] + right[0];
        // 如果不偷当前节点，那么可以选择偷或者不偷左右子节点，取最大值
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
};

// 定义输入输出函数

int main() {
   // 创建一棵示例二叉树：3,4,5,1,3,null,1
   TreeNode* root = new TreeNode(3);
   root->left = new TreeNode(4);
   root->right = new TreeNode(5);
   root->left->left = new TreeNode(1);
   root->left->right = new TreeNode(3);
   root->right->right = new TreeNode(1);

   // 创建一个解决方案对象并调用主函数得到结果：9
   Solution s;
   cout << "The maximum amount of money that can be robbed is: " << s.rob(root) << endl;

   return 0;
}