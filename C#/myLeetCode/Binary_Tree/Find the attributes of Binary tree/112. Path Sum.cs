// 112. Path Sum
// https://leetcode.com/problems/path-sum/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public bool HasPathSum(TreeNode? root, int sum) {
        if (root == null) return false;

        // 如果是叶子节点，检查sum是否等于节点值
        if (root.left == null && root.right == null) return sum == root.val;

        // 递归检查左子树和右子树
        return HasPathSum(root.left, sum - root.val) || HasPathSum(root.right, sum - root.val);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(5) {
            left = new TreeNode(4) {
                left = new TreeNode(11) {
                    left = new TreeNode(7),
                    right = new TreeNode(2)
                }
            },
            right = new TreeNode(8) {
                left = new TreeNode(13),
                right = new TreeNode(4) {
                    right = new TreeNode(1)
                }
            }
        };

        int targetSum = 22;
        bool result = solution.HasPathSum(tree, targetSum);

        // 打印结果
        Console.WriteLine($"Does the tree have a path with sum {targetSum}? {result}");
    }
}
