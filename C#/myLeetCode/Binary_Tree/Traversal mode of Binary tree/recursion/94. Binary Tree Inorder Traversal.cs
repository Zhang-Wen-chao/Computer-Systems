// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    public IList<int> InorderTraversal(TreeNode root) {
        IList<int> result = new List<int>();
        Inorder(root, result);
        return result;
    }

    private void Inorder(TreeNode node, IList<int> result) {
        if (node == null) return;

        Inorder(node.left, result);
        result.Add(node.val);
        Inorder(node.right, result);
    }
}

public class Program {
    public static void Main() {
        Solution solution = new Solution();

        TreeNode tree = new TreeNode(1) {
            right = new TreeNode(2) {
                left = new TreeNode(3)
            }
        };

        IList<int> inorderTraversal = solution.InorderTraversal(tree);

        Console.WriteLine("Inorder Traversal:");
        foreach (int val in inorderTraversal) {
            Console.Write(val + " ");
        }
    }
}
