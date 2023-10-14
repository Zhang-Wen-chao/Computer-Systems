// 100. Same Tree
// https://leetcode.com/problems/same-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;  // 标记为可空
    public TreeNode? right; // 标记为可空
    public TreeNode(int x) { val = x; }
}


public class Solution {
    public bool IsSameTree(TreeNode? p, TreeNode? q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        if (p.val != q.val) return false;

        return IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree1 = new TreeNode(1) {
            left = new TreeNode(2),
            right = new TreeNode(3)
        };

        TreeNode tree2 = new TreeNode(1) {
            left = new TreeNode(2),
            right = new TreeNode(3)
        };

        bool result = solution.IsSameTree(tree1, tree2);

        // 打印结果
        Console.WriteLine($"Are the trees same? {result}");
    }
}
