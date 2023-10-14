// 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public bool IsValidBST(TreeNode? root) {
        return IsValidBST(root, long.MinValue, long.MaxValue);
    }

    private bool IsValidBST(TreeNode? node, long min, long max) {
        if (node == null) return true;

        if (node.val <= min || node.val >= max) return false;

        return IsValidBST(node.left, min, node.val) && IsValidBST(node.right, node.val, max);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree1 = new TreeNode(2) {
            left = new TreeNode(1),
            right = new TreeNode(3)
        };

        bool isValid1 = solution.IsValidBST(tree1);

        TreeNode tree2 = new TreeNode(5) {
            left = new TreeNode(1),
            right = new TreeNode(4) {
                left = new TreeNode(3),
                right = new TreeNode(6)
            }
        };

        bool isValid2 = solution.IsValidBST(tree2);

        // 打印结果
        Console.WriteLine($"Is tree1 a valid BST? {isValid1}");
        Console.WriteLine($"Is tree2 a valid BST? {isValid2}");
    }
}
