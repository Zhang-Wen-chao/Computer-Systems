// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public int MaxDepth(TreeNode? root) {
        if (root == null) return 0;
        int leftDepth = MaxDepth(root.left);
        int rightDepth = MaxDepth(root.right);
        return Math.Max(leftDepth, rightDepth) + 1;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            left = new TreeNode(2) {
                left = new TreeNode(3),
                right = new TreeNode(4) {
                    left = new TreeNode(5)
                }
            },
            right = new TreeNode(2)
        };

        int depth = solution.MaxDepth(tree);

        // 打印结果
        Console.WriteLine($"Maximum depth of the tree: {depth}");
    }
}
