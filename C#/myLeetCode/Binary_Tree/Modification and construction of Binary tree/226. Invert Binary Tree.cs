// 226. Invert Binary Tree
// https://leetcode.com/problems/invert-binary-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? InvertTree(TreeNode? root) {
        if (root == null) return null;

        TreeNode? temp = root.left;
        root.left = InvertTree(root.right);
        root.right = InvertTree(temp);

        return root;
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
            right = new TreeNode(7) {
                left = new TreeNode(6),
                right = new TreeNode(9)
            }
        };

        Console.WriteLine("Original Tree:");
        PrintTree(tree);

        TreeNode? invertedTree = solution.InvertTree(tree);

        Console.WriteLine("\nInverted Tree:");
        PrintTree(invertedTree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}
