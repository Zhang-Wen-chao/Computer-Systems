// 111. Minimum Depth of Binary Tree
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public int MinDepth(TreeNode? root) {
        if (root == null) return 0;

        int leftDepth = MinDepth(root.left);
        int rightDepth = MinDepth(root.right);

        if (leftDepth == 0 || rightDepth == 0) {
            return leftDepth + rightDepth + 1;
        }

        return Math.Min(leftDepth, rightDepth) + 1;
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
                right = new TreeNode(3)
            }
        };

        int depth = solution.MinDepth(tree);

        // 打印结果
        Console.WriteLine($"Minimum depth of the tree: {depth}");
    }
}
