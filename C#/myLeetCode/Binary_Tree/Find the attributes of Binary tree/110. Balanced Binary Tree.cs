// 110. Balanced Binary Tree
// https://leetcode.com/problems/balanced-binary-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public bool IsBalanced(TreeNode? root) {
        return CheckBalance(root) != -1;
    }

    private int CheckBalance(TreeNode? node) {
        if (node == null) return 0;

        int leftDepth = CheckBalance(node.left);
        if (leftDepth == -1) return -1;

        int rightDepth = CheckBalance(node.right);
        if (rightDepth == -1) return -1;

        if (Math.Abs(leftDepth - rightDepth) > 1) return -1;

        return Math.Max(leftDepth, rightDepth) + 1;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            left = new TreeNode(2) {
                left = new TreeNode(3),
                right = new TreeNode(4)
            },
            right = new TreeNode(2) {
                right = new TreeNode(3) {
                    right = new TreeNode(4)
                }
            }
        };

        bool result = solution.IsBalanced(tree);

        // 打印结果
        Console.WriteLine($"Is the tree balanced? {result}");
    }
}
