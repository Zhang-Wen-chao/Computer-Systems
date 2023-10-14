// 101. Symmetric Tree
// https://leetcode.com/problems/symmetric-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public bool IsSymmetric(TreeNode? root) {
        if (root == null) return true;
        return IsMirror(root.left, root.right);
    }

    private bool IsMirror(TreeNode? left, TreeNode? right) {
        if (left == null && right == null) return true;
        if (left == null || right == null) return false;
        if (left.val != right.val) return false;

        return IsMirror(left.left, right.right) && IsMirror(left.right, right.left);
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
                left = new TreeNode(4),
                right = new TreeNode(3)
            }
        };

        bool result = solution.IsSymmetric(tree);

        // 打印结果
        Console.WriteLine($"Is the tree symmetric? {result}");
    }
}
