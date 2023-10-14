// 669. Trim a Binary Search Tree
// https://leetcode.com/problems/trim-a-binary-search-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? TrimBST(TreeNode? root, int L, int R) {
        if (root == null) return null;

        if (root.val < L) return TrimBST(root.right, L, R);
        if (root.val > R) return TrimBST(root.left, L, R);

        root.left = TrimBST(root.left, L, R);
        root.right = TrimBST(root.right, L, R);

        return root;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(3) {
            left = new TreeNode(0) {
                right = new TreeNode(2) {
                    left = new TreeNode(1)
                }
            },
            right = new TreeNode(4)
        };

        int L = 1, R = 3;
        TreeNode? trimmedTree = solution.TrimBST(tree, L, R);

        // 打印结果
        PrintTree(trimmedTree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}
