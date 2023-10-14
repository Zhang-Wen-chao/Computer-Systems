// 530. Minimum Absolute Difference in BST
// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    private int? prev = null;
    private int minDiff = int.MaxValue;

    public int GetMinimumDifference(TreeNode? root) {
        if (root == null) return minDiff;

        Traverse(root);

        return minDiff;
    }

    private void Traverse(TreeNode? node) {
        if (node == null) return;

        Traverse(node.left);

        if (prev.HasValue) {
            minDiff = Math.Min(minDiff, node.val - prev.Value);
        }

        prev = node.val;
        Traverse(node.right);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(4) {
            left = new TreeNode(2) {
                left = new TreeNode(1),
                right = new TreeNode(3)
            },
            right = new TreeNode(6)
        };

        int minDifference = solution.GetMinimumDifference(tree);

        // 打印结果
        Console.WriteLine($"Minimum Absolute Difference in BST: {minDifference}");
    }
}
