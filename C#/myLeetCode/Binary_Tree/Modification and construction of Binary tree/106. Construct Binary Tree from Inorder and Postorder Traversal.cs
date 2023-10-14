// 106. Construct Binary Tree from Inorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 已知后序与中序,建树

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    private int postIndex;
    private Dictionary<int, int> inorderIndexMap = new Dictionary<int, int>();

    public TreeNode BuildTree(int[] inorder, int[] postorder) {
        postIndex = postorder.Length - 1;
        for (int i = 0; i < inorder.Length; i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return BuildTree(inorder, 0, inorder.Length - 1, postorder);
    }

    private TreeNode BuildTree(int[] inorder, int inStart, int inEnd, int[] postorder) {
        if (inStart > inEnd) return null;

        TreeNode root = new TreeNode(postorder[postIndex--]);

        if (inStart == inEnd) return root;

        int inIndex = inorderIndexMap[root.val];

        root.right = BuildTree(inorder, inIndex + 1, inEnd, postorder);
        root.left = BuildTree(inorder, inStart, inIndex - 1, postorder);

        return root;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] inorder = { 9, 3, 15, 20, 7 };
        int[] postorder = { 9, 15, 7, 20, 3 };

        TreeNode tree = solution.BuildTree(inorder, postorder);

        // 打印结果
        PrintTree(tree);
    }

    public static void PrintTree(TreeNode? root) {
        if (root == null) return;

        PrintTree(root.left);
        Console.Write(root.val + " ");
        PrintTree(root.right);
    }
}
