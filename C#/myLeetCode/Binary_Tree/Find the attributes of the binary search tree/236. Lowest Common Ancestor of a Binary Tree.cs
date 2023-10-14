// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? LowestCommonAncestor(TreeNode? root, TreeNode? p, TreeNode? q) {
        if (root == null || root == p || root == q) return root;

        TreeNode? left = LowestCommonAncestor(root.left, p, q);
        TreeNode? right = LowestCommonAncestor(root.right, p, q);

        if (left != null && right != null) return root;
        return left ?? right;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(3) {
            left = new TreeNode(5) {
                left = new TreeNode(6),
                right = new TreeNode(2) {
                    left = new TreeNode(7),
                    right = new TreeNode(4)
                }
            },
            right = new TreeNode(1) {
                left = new TreeNode(0),
                right = new TreeNode(8)
            }
        };

        TreeNode? p = tree.left;  // Node with value 5
        TreeNode? q = tree.right; // Node with value 1

        TreeNode? lca = solution.LowestCommonAncestor(tree, p, q);

        // 打印结果
        Console.WriteLine($"Lowest Common Ancestor of {p?.val} and {q?.val} is: {lca?.val}");
    }
}
