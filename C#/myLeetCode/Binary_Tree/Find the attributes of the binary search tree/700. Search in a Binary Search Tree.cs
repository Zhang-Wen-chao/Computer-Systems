// 700. Search in a Binary Search Tree
// https://leetcode.com/problems/search-in-a-binary-search-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode? SearchBST(TreeNode? root, int val) {
        if (root == null) return null;

        if (root.val == val) return root;
        else if (root.val > val) return SearchBST(root.left, val);
        else return SearchBST(root.right, val);
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
            right = new TreeNode(7)
        };

        int searchValue = 2;
        TreeNode? resultTree = solution.SearchBST(tree, searchValue);

        // 打印结果
        PrintTree(resultTree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}
