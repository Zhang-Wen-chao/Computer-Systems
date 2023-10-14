// 701. Insert into a Binary Search Tree
// https://leetcode.com/problems/insert-into-a-binary-search-tree/

using System;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode InsertIntoBST(TreeNode? root, int val) {
        if (root == null) return new TreeNode(val);

        if (val < root.val) {
            root.left = InsertIntoBST(root.left, val);
        } else {
            root.right = InsertIntoBST(root.right, val);
        }

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
            right = new TreeNode(7)
        };

        int valueToInsert = 5;
        TreeNode newTree = solution.InsertIntoBST(tree, valueToInsert);

        // 打印结果
        PrintTree(newTree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}
