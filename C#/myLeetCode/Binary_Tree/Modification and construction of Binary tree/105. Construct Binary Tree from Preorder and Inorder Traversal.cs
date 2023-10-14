// 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// 已知先序与中序,输出后序
/*
因为前序（根左右）最先出现的总是根结点，所以令root为前序中当前的根结点下标（并且同时把一棵树分为左子树和右子树）。start为当前需要打印的子树在中序中的最左边的下标，end为当前需要打印的子树在中序中最右边的下标。递归打印这棵树的后序，递归出口为start > end。i为root所表示的值在中序中的下标，所以i即是分隔中序中对应root结点的左子树和右子树的下标。
先打印左子树，后打印右子树，最后输出当前根结点pre[root]的值。
*/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode? left;
    public TreeNode? right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    private int preIndex = 0;
    private Dictionary<int, int> inorderIndexMap = new Dictionary<int, int>();

    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        for (int i = 0; i < inorder.Length; i++) {
            inorderIndexMap[inorder[i]] = i;
        }
        return BuildTree(preorder, 0, inorder.Length - 1);
    }

    private TreeNode BuildTree(int[] preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return null;

        TreeNode root = new TreeNode(preorder[preIndex++]);

        if (inStart == inEnd) return root;

        int inIndex = inorderIndexMap[root.val];

        root.left = BuildTree(preorder, inStart, inIndex - 1);
        root.right = BuildTree(preorder, inIndex + 1, inEnd);

        return root;
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        int[] preorder = { 3, 9, 20, 15, 7 };
        int[] inorder = { 9, 3, 15, 20, 7 };

        TreeNode tree = solution.BuildTree(preorder, inorder);

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
