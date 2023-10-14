// 572. Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public bool IsSubtree(TreeNode? s, TreeNode? t) {
        if (s == null) return false;
        if (IsSameTree(s, t)) return true;
        return IsSubtree(s.left, t) || IsSubtree(s.right, t);
    }

    private bool IsSameTree(TreeNode? s, TreeNode? t) {
        if (s == null && t == null) return true;
        if (s == null || t == null) return false;
        return s.val == t.val && IsSameTree(s.left, t.left) && IsSameTree(s.right, t.right);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree1 = new TreeNode(3) {
            left = new TreeNode(4) {
                left = new TreeNode(1),
                right = new TreeNode(2)
            },
            right = new TreeNode(5)
        };

        TreeNode tree2 = new TreeNode(4) {
            left = new TreeNode(1),
            right = new TreeNode(2)
        };

        bool isSubtree = solution.IsSubtree(tree1, tree2);

        // 打印结果
        Console.WriteLine($"Is tree2 a subtree of tree1? {isSubtree}");
    }
}
