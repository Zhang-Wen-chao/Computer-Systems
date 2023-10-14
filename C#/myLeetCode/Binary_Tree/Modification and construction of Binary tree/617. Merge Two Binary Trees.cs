// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/
// 617. Merge Two Binary Trees
// https://leetcode.com/problems/merge-two-binary-trees/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? MergeTrees(TreeNode? t1, TreeNode? t2) {
        if (t1 == null) return t2;
        if (t2 == null) return t1;

        t1.val += t2.val;
        t1.left = MergeTrees(t1.left, t2.left);
        t1.right = MergeTrees(t1.right, t2.right);

        return t1;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree1 = new TreeNode(1) {
            left = new TreeNode(3) {
                left = new TreeNode(5)
            },
            right = new TreeNode(2)
        };

        TreeNode tree2 = new TreeNode(2) {
            left = new TreeNode(1) {
                right = new TreeNode(4)
            },
            right = new TreeNode(3) {
                right = new TreeNode(7)
            }
        };

        Console.WriteLine("Tree 1:");
        PrintTree(tree1);

        Console.WriteLine("\nTree 2:");
        PrintTree(tree2);

        TreeNode? mergedTree = solution.MergeTrees(tree1, tree2);

        Console.WriteLine("\nMerged Tree:");
        PrintTree(mergedTree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}
